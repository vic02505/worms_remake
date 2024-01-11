#include "messages/server/GameInfo.h"

#include <utility>

GameInfo::GameInfo() : m_IdAction(InitGameEnum::INVALID) {}

GameInfo::GameInfo(InitGameEnum idAction, int idPlayer) {
    m_IdAction = idAction;
    m_GameProperties.emplace_back(idPlayer);
}

GameProperty::GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players)
    : m_idGame(idGame), m_GameName(std::move(gameName)), m_MapName(std::move(mapName)),
    m_PlayersConnected(playersConnected), m_Players(players) {}

GameProperty::GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players,
                           int idPlayer, std::string playerName) : m_idGame(idGame), m_GameName(std::move(gameName)),
                           m_MapName(std::move(mapName)), m_PlayersConnected(playersConnected), m_Players(players),
                           m_IdPlayer(idPlayer), m_PlayerName(std::move(playerName)) {}

GameProperty::GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players,
                           std::string playerName) : m_idGame(idGame), m_GameName(std::move(gameName)),
                           m_MapName(std::move(mapName)), m_PlayersConnected(playersConnected),
                           m_Players(players), m_PlayerName(std::move(playerName)) {}

GameInfo::GameInfo(InitGameEnum idAction, std::vector<GameProperty> gameProperties) : m_IdAction(idAction),
    m_GameProperties(std::move(gameProperties)) {}

void GameInfo::setIdAction(InitGameEnum idAction) {
    m_IdAction = idAction;
}

InitGameEnum GameInfo::getIdAction() const {
    return m_IdAction;
}

void GameInfo::setGameProperties(std::vector<GameProperty> gameProperties) {
    m_GameProperties = std::move(gameProperties);
}

std::vector<GameProperty> GameInfo::getGameProperties() const {
    return m_GameProperties;
}


