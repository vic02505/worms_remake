#pragma once

#include <atomic>
#include <iostream>

#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/messages/server/GameUpdate.h"

class ClientSender : public Thread {
private:
    Protocol& m_Protocol;
    ProtectedQueue<GameUpdate>* m_SelfQueue;
    int m_IdPlayer;
    std::atomic<bool> m_KeepRunning;
 public:
    ClientSender(Protocol& protocol, ProtectedQueue<GameUpdate>* selfQueue, int idPlayer);
    void setPlayerId(int idPlayer);
    void run() override;
    void stop();
    bool isRunning() const;
    ~ClientSender() override = default;
    ClientSender(const ClientSender&) = delete;
    ClientSender(ClientSender&& other) = delete;
};
