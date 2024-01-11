#pragma once

#include <atomic>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/socket.h"
#include "exceptions/UnExpectedException.h"
#include "Client.h"
#include "MatchesMonitor.h"

class Server : public Thread {
private:
    Socket socket;
    std::atomic<bool> m_KeepRunning;
    std::list<Client> m_Clients;
    MatchesMonitor m_Games;

private:
    void reapDead();
    void killAll();
    void unexpectedError();
public:
    explicit Server(const char* port);

    void run() override;
    void stop();
    void acceptConnection();

    ~Server() override = default;
    Server(const Server&) = delete;
    Server(Server&& other) = delete;
};
