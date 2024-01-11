#pragma once

#include <atomic>
#include <unordered_map>
#include "../../common_libs/include/Thread.h"
#include "world/GameWorld.h"
#include "messages/user_actions/UserAction.h"
#include "world/instructions/InstructionFactory.h"
#include "world/entities/WProyectile.h"

class Game : public Thread {
private:
    int m_IdGame;
    std::string m_GameName;
    std::string m_MapName;
    int m_Players;
    std::unordered_map<int, ProtectedQueue<GameUpdate>*> m_QClientUpdates;
    ProtectedQueue<UserAction> m_InputActions;
    std::atomic<bool> m_KeepRunning;
    std::atomic<bool> m_HasStarted;
    int m_PopMessageQuantity;
    GameWorld world;
    std::unordered_map<int, std::string&> m_PlayersInfo;

public:
    Game(int id, std::string gameName, std::string mapName, int players);
    void run() override;
    int getIdGame() const;
    std::string getGameName() const;
    std::string getMapName() const;
    int getPlayers() const;
    int addPlayer(ProtectedQueue<GameUpdate>* qClientUpdates, std::string& playerName);
    void removePlayer(int idPlayer);
    ProtectedQueue<UserAction>* getInputActions();
    void stop();
    ~Game() override = default;
    Game(const Game&) = delete;
    Game(Game&& other) = delete;

    bool isReadyToStart();

    std::unordered_map<int, ProtectedQueue<GameUpdate>*>* getClientUpdates();
    void setupWorld();
    bool isStillPlayable();
    void kill();
    bool hasStarted();

private:
    void pushUpdatesToClients(std::reference_wrapper<std::vector<GameUpdate>> updates);
    void pushUpdateToClients(GameUpdate& update);

    void sendInfoTurns(int playerId, double secondsPerTurn, GameAction infoTurn);
    void processTurns(TurnHandler& turnHandler, InstructionFactory& instructionFactory);
    void waitFrameTime();

    void processAttackTurn(TurnHandler &turnHandler, InstructionFactory &instructionFactory, UserAction userAction);
    void processNormalTurn(TurnHandler& turnHandler, InstructionFactory& instructionFactory, UserAction& userAction);
    void finishTurn(int idCurrentPlayer, const ActionType& type);
    void startTurn(TurnHandler& turnHandler);
    void allElementsIdle();

    void checkWormsNear(WProyectile* proyectilCollide);

    void sendEndGame(int winner);

    void wormsGettingDamage();

    void wormsGrave(std::vector<int> &deadWorms);
};
