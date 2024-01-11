#include "../include/Client.h"

#define ID_PLAYER_INVALID (-1)

Client::Client(Socket peer, MatchesMonitor* matches) : m_Protocol(std::move(peer)), m_KeepRunning(true),
    m_Matches(matches), m_UpdatesGame(100), m_Sender(std::ref(m_Protocol), &m_UpdatesGame, ID_PLAYER_INVALID) {}

void Client::run() {
    try {
        while (isRunning() && !hasGame) {
            lobbyGame();
        }
        if (hasGame) {
            initGame();
        }
    } catch (const LibError& e) {
        std::cerr << "LibError exception e.what(): " << e.what() << std::endl;
    } catch (const std::exception &e1) {
        std::cerr << "Unexpected error e.what(): " << e1.what() << std::endl;
    }
    destroyClient();
}

void Client::initGame() {
    sendMap();
    m_Sender.setPlayerId(m_IdPlayer);
    m_Sender.start();
    while (isRunning()) {
        try{
            m_InputActions->push(m_Protocol.recvUserAction());
        } catch (const LibError& e) {
            m_KeepRunning.store(false);
            break;
        } catch (...) {
            //should do nothing, either protocol has closed or queue is closed 
        }
    }
    if (m_Sender.isRunning()) {
        m_Sender.stop();
    }
    m_Sender.join();
}

void Client::lobbyGame() {
    GameInfo clientResponse = m_Protocol.recvGameInfo();
    if (!m_Protocol.isClosed()) {
        switch (clientResponse.getIdAction()) {
            case CREATE_GAME: {
                m_IdGame = m_Matches->createGame(clientResponse.getGameProperties()[0].m_GameName,
                                                 clientResponse.getGameProperties()[0].m_MapName,
                                                 clientResponse.getGameProperties()[0].m_Players);
                m_PlayerName = clientResponse.getGameProperties()[0].m_PlayerName;
                m_IdPlayer = m_Matches->addPlayer(m_IdGame, &m_UpdatesGame, std::ref(m_PlayerName));
                GameInfo response(InitGameEnum::ID_PLAYER, m_IdPlayer);
                m_Protocol.sendGameInfo(response);
                m_InputActions = m_Matches->getInputActionGame(m_IdGame);
                hasGame = true;
                break;
            }
            case JOIN_GAME: {
                m_IdGame = clientResponse.getGameProperties()[0].m_idGame;
                m_PlayerName = clientResponse.getGameProperties()[0].m_PlayerName;
                m_IdPlayer = m_Matches->addPlayer(m_IdGame, &m_UpdatesGame, std::ref(m_PlayerName));
                GameInfo response(InitGameEnum::ID_PLAYER, m_IdPlayer);
                m_Protocol.sendGameInfo(response);
                m_InputActions = m_Matches->getInputActionGame(m_IdGame);
                hasGame = true;
                break;
            }
            case LIST_GAMES: {
                GameInfo gameInfo(LIST_GAMES, m_Matches->getGameProperties());
                m_Protocol.sendGameInfo(std::ref(gameInfo));
            }
            default: {
                break;
            }
        }
    }
}

bool Client::isDead() {
    return !m_KeepRunning.load();
}

void Client::stop() {
    m_KeepRunning.store(false);
}

void Client::kill() {
    m_KeepRunning.store(false);
    if (!m_Protocol.isClosed()) {
        m_Protocol.shutdown(SHUT_RDWR);
        m_Protocol.close();
    }
}

void Client::sendMap() {
    std::vector<Grd> map = ParseMapFromFile::parse(m_Matches->getMapName(m_IdGame));
    m_Protocol.sendMap(std::ref(map));
}

void Client::destroyClient() {
    if (hasGame) {
        m_Matches->removePlayer(m_IdGame, m_IdPlayer);
    }
    if (m_KeepRunning.load()) {
        kill();
    }
}

int Client::getIdPlayer() const {
    return m_IdPlayer;
}

int Client::getIdGame() const {
    return m_IdGame;
}

bool Client::isRunning() {
    return m_KeepRunning.load() && !m_Protocol.isClosed();
}

