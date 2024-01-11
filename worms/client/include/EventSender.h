#ifndef CLIENT_SENDER_H
#define CLIENT_SENDER_H

#include <SDL_events.h>
#include <iostream>
#include <string>
#include <atomic>
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/messages/server/GameInfo.h"
#include "../../common_libs/include/messages/user_actions/UserAction.h"
#include "ProtectedQueue.h"
#include "../../common_libs/include/messages/user_actions/ToolID.h"
#include "utils/WorldScale.h"

class EventSender : public Thread {
 private:
    Protocol& m_Protocol;
    std::atomic<bool> m_IsMyTurn;
    std::atomic<bool> m_KeepRunning;
    int m_IdPlayer;
    ProtectedQueue<std::string>& m_SettingsQueue;

    WeaponID m_WeaponId;
    ToolID m_ToolId;
    std::chrono::time_point<std::chrono::system_clock> m_StartAttackTime;

private:
    UserAction attack();

public:
    EventSender(Protocol& protocol, int idPlayer, ProtectedQueue<std::string>& settingsQueue, bool isMyTurn);
    void run() override;
    bool isRunning();
    void stop();
    void setItsMyTurn(bool isMyTurn);

    void setIsRunning(bool isRunning);
};

#endif