#pragma once

#include "Protocol.h"
#include "ProtectedQueue.h"
#include "GameClient.h"
#include "EventSender.h"
#include "client_receiver.h"
#include "GameClient.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class ClientManager {
 private:
    Protocol* m_Protocol;
    int m_IdPlayer;
    int m_CantPlayers;
    GameClient m_Game{};
    ProtectedQueue<std::string> settingsQueue;
    ProtectedQueue<GameUpdate> gameUpdates;
    bool m_KeepRunning;
    bool m_EndGame;
    std::string m_Winner;
    bool m_YouWin;

public:
    ClientManager(Protocol* protocol, int idPlayer, int cantPlayers);
    void init();
    void gameLoop(EventSender& eventSender);
    ~ClientManager() = default;
    ClientManager(const ClientManager&) = delete;
    ClientManager(ClientManager&&) = delete;

private:
    void endGameWindow();

    GameUpdate initStage();
};