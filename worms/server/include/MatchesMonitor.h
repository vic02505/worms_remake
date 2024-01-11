#pragma once

#include <mutex>
#include <unordered_map>
#include "Game.h"
#include "messages/server/GameInfo.h"

class MatchesMonitor {
 private:
    std::mutex m_Mutex;
    std::unordered_map<int, Game*> m_Games;
private:
    void removeGame(int id);
public:
    MatchesMonitor();
    int createGame(std::string gameName, std::string mapName, int players);
    std::string getMapName(int idGame);
    std::vector<GameProperty> getGameProperties();
    int addPlayer(int id, ProtectedQueue<GameUpdate>* qClientUpdates, std::string& playerName);
    ProtectedQueue<UserAction>* getInputActionGame(int idGame);
    ~MatchesMonitor() = default;

    void removePlayer(int idGame, int idPlayer);
};
