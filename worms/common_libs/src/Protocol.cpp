#include "../include/Protocol.h"

Protocol::Protocol(Socket socket): socket(std::move(socket)), wasClosed(false) {}

Protocol::Protocol(const std::string& hostname, const std::string& servname):
        socket(hostname.c_str(), servname.c_str()), wasClosed(false) {}

/*
 * PRIVATE METHODS
 * */
uint8_t Protocol::recvByte() {
    uint8_t aux;
    socket.recvall(&aux, 1, &wasClosed);
    return aux;
}
uint16_t Protocol::recvTwoBytes() {
    uint16_t aux;
    socket.recvall(&aux, 2, &wasClosed);
    return ntohs(aux);
}

uint32_t Protocol::recvFourBytes() {
    uint32_t aux;
    socket.recvall(&aux, 4, &wasClosed);
    return ntohl(aux);
}

float Protocol::recvFloat() {
    uint32_t aux = recvFourBytes();
    return *reinterpret_cast<float*>(&aux);
}

std::string Protocol::recvString() {
    uint16_t size = recvTwoBytes();
    std::vector<char> messageFromServer(size + 1);
    socket.recvall(messageFromServer.data(), size, &wasClosed);
    messageFromServer[size] = '\0';
    return messageFromServer.data();
}

void Protocol::sendByte(uint8_t byte) {
    if (!wasClosed)
        socket.sendall(&byte, 1, &wasClosed);
}

void Protocol::sendTwoBytes(uint16_t bytes) {
    if (!wasClosed) {
        uint16_t aux = htons(bytes);
        socket.sendall(&aux, 2, &wasClosed);
    }
}

void Protocol::sendFourBytes(uint32_t bytes) {
    if (!wasClosed) {
        uint32_t aux = htonl(bytes);
        socket.sendall(&aux, 4, &wasClosed);
    }
}

void Protocol::sendFloat(float f) {
    if (!wasClosed) {
        uint32_t aux = htonl(*reinterpret_cast<uint32_t*>(&f));
        socket.sendall(&aux, 4, &wasClosed);
    }
}

void Protocol::sendString(const std::string &message) {
    uint16_t size = message.size();
    sendTwoBytes(size);
    socket.sendall(message.c_str(), size, &wasClosed);
}

/*
 * PUBLIC METHODS
 * */

void Protocol::sendGameInfo(GameInfo& gameInfo) {
    sendByte(gameInfo.getIdAction());
    sendByte(gameInfo.getGameProperties().size());
    for (auto& gameProperty : gameInfo.getGameProperties()) {
        sendByte(gameProperty.m_idGame);
        sendString(gameProperty.m_GameName);
        sendString(gameProperty.m_MapName);
        sendByte(gameProperty.m_PlayersConnected);
        sendByte(gameProperty.m_Players);
        sendByte(gameProperty.m_IdPlayer);
        sendString(gameProperty.m_PlayerName);
    }
}

void Protocol::sendMap(std::reference_wrapper<std::vector<Grd>> map) {
    sendByte(map.get().size());
    for (auto& grd : map.get()) {
        sendByte(grd.grdType);
        sendFloat(grd.x);
        sendFloat(grd.y);
        sendFloat(grd.width);
        sendFloat(grd.height);
    }
}

void Protocol::sendGameUpdate(GameUpdate &update) {
    sendByte(update.player_id);
    sendString(update.m_PlayerName);
    sendFloat(update.x_pos);
    sendFloat(update.y_pos);
    sendFloat(update.width);
    sendFloat(update.height);

    sendByte(update.m_Movement);
    sendByte(update.m_Weapon);
    sendByte(update.m_IsAttacking ? 0x01 : 0x00);
    sendByte(update.m_Health);
    sendByte(update.m_Dir);
    sendByte(update.m_SelfCondition);
    sendFloat(update.m_VelocityX);
    sendFloat(update.m_VelocityY);
    sendByte(update.m_CurrentSprite);
    sendByte(update.m_TurnInfo);
    sendFloat(update.m_WeaponAngle);
    sendByte(static_cast<uint8_t>(update.m_SecondsPerTurn));
    sendByte(update.m_InfoWorm ? 0x01 : 0x00);
    sendByte(update.m_Tool);
}

GameInfo Protocol::recvGameInfo() {
    GameInfo gameInfo;
    gameInfo.setIdAction(InitGameEnum(recvByte()));
    uint8_t size = recvByte();
    std::vector<GameProperty> gameProperties;
    for (int i = 0; i < size; i++) {
        int idGame = recvByte();
        std::string gameName = recvString();
        std::string mapName = recvString();
        int players = recvByte();
        int playersConnected = recvByte();
        int idPlayer = recvByte();
        std::string playerName = recvString();
        gameProperties.emplace_back(idGame, gameName, mapName, players, playersConnected, idPlayer, playerName);
    }
    gameInfo.setGameProperties(gameProperties);
    return gameInfo;
}

std::vector<Grd> Protocol::recvMap() {
    std::vector<Grd> map;
    uint8_t size = recvByte();
    for (int i = 0; i < size; i++) {
        uint8_t grdType = recvByte();
        float x = recvFloat();
        float y = recvFloat();
        float w = recvFloat();
        float h = recvFloat();
        map.emplace_back(grdType, x, y, w, h);
    }
    return map;
}

GameUpdate Protocol::recvGameUpdate() {
    GameUpdate update{};
    update.player_id = recvByte();
    update.m_PlayerName = recvString();
    update.x_pos = recvFloat();
    update.y_pos = recvFloat();
    update.width = recvFloat();
    update.height = recvFloat();

    update.m_Movement = GameAction(recvByte());
    update.m_Weapon = WeaponID(recvByte());
    update.m_IsAttacking = recvByte() == 0x01;
    update.m_Health = recvByte();
    update.m_Dir = Direction(recvByte());
    update.m_SelfCondition = GameAction(recvByte());
    update.m_VelocityX = recvFloat();
    update.m_VelocityY = recvFloat();
    update.m_CurrentSprite = SpritesEnum(recvByte());
    update.m_TurnInfo = GameAction(recvByte());
    update.m_WeaponAngle = recvFloat();
    update.m_SecondsPerTurn = static_cast<double>(recvByte());
    update.m_InfoWorm = recvByte() == 0x01;
    update.m_Tool = ToolID(recvByte());
    return update;
}

void Protocol::close() { socket.close(); }
void Protocol::shutdown(int mode) { socket.shutdown(mode); }
Protocol::~Protocol() {
    try {
        socket.shutdown(SHUT_RDWR);
        socket.close();
    } catch (const LibError& e) {
        socket.close();
    }
}
bool Protocol::isClosed() const { return wasClosed; }

void Protocol::sendUserAction(UserAction action) {
    sendByte(action.getAction());
    sendByte(action.getIdPlayer());
    sendByte(action.getParam1());
    sendByte(action.getParam2());
    sendFloat(action.getParam3());
    sendFloat(action.getParam4());
}

UserAction Protocol::recvUserAction() {
    UserAction userAction;
    userAction.setAction(ActionType(recvByte()));
    userAction.setIdPlayer(recvByte());
    userAction.setParam1(recvByte());
    userAction.setParam2(recvByte());
    userAction.setParam3(recvFloat());
    userAction.setParam4(recvFloat());
    return userAction;
}

