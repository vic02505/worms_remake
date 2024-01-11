#pragma once

#include <cstdint>
#include <vector>
#include <utility>
#include <string>
#include "messages/server/InitGameEnum.h"

struct GameProperty {
    int m_idGame{};
    std::string m_GameName;
    std::string m_MapName;
    int m_PlayersConnected{};
    int m_Players{};
    int m_IdPlayer = 0;
    std::string m_PlayerName{};

    GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players);
    GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players,
                 std::string playerName);
    GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players, int idPlayer,
                 std::string playerName);
    explicit GameProperty(int idPlayer) : m_IdPlayer(idPlayer) {}
};

class GameInfo {
private:
    InitGameEnum m_IdAction;
    std::vector<GameProperty> m_GameProperties;
public:
    GameInfo(InitGameEnum idAction, std::vector<GameProperty> gameProperties);
    GameInfo(InitGameEnum idAction, int idPlayer);
    GameInfo();
    [[nodiscard]] InitGameEnum getIdAction() const;
    [[nodiscard]] std::vector<GameProperty> getGameProperties() const;
    //setter
    void setIdAction(InitGameEnum idAction);
    void setGameProperties(std::vector<GameProperty> gameProperties);

    ~GameInfo() = default;
    GameInfo(GameInfo&& other) = default;
    GameInfo(const GameInfo& other) = default;
    GameInfo& operator=(GameInfo&& other) = default;
};