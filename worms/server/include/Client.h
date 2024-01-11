#pragma once

#include <atomic>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>

#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/liberror.h"
#include "../../common_libs/include/socket.h"
#include "../../common_libs/include/ParseMapFromFile.h"
#include "ClientSender.h"
#include "MatchesMonitor.h"
#include "messages/server/InitGameEnum.h"


class Client : public Thread {
private:
    Protocol m_Protocol;
    std::atomic<bool> m_KeepRunning;
    MatchesMonitor* m_Matches;
    int m_IdGame{};
    int m_IdPlayer{};
    bool hasGame = false;
    ProtectedQueue<GameUpdate> m_UpdatesGame;
    ProtectedQueue<UserAction>* m_InputActions{};
    ClientSender m_Sender;
    std::string m_PlayerName;
public:
    Client(Socket peer, MatchesMonitor* games);
    bool isDead();
    void stop();
    void kill();
    void run() override;
    [[nodiscard]] int getIdPlayer() const;
    [[nodiscard]] int getIdGame() const;
    ~Client() override = default;
    Client(const Client&) = delete;
    Client(Client&& other) = delete;
private:
    void sendMap();

    void lobbyGame();

    void destroyClient();

    bool isRunning();

    void initGame();
};
