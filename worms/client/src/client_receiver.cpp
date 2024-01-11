#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocol, ProtectedQueue<GameUpdate>& gameUpdates,
                               EventSender& eventSender, int idPlayer): m_Protocol(protocol),
                                                                        m_GameUpdates(gameUpdates),
                                                                        m_EventSender(eventSender),
                                                                        m_IdPlayer(idPlayer) {}

void  ClientReceiver::run() {
    try{
        while (!m_Protocol.isClosed()) {
            auto gameUpdate = m_Protocol.recvGameUpdate();
            if (gameUpdate.m_TurnInfo != INVALID_ACTION) {
                manageTurn(std::ref(gameUpdate), gameUpdate.player_id);
            } else {
                m_GameUpdates.push(gameUpdate);
            }
        }
    } catch (const LibError& e) {
        //should do nothing, end game.
    } catch (std::exception &e1) {
        std::cerr << "Unexpected error e.what(): " << e1.what() << std::endl;
    }
}

void ClientReceiver::manageTurn(const GameUpdate& turnInfo, int id) {
    if (turnInfo.m_TurnInfo == END_GAME) {
        m_GameUpdates.push(turnInfo);
        m_Protocol.shutdown(SHUT_RDWR);
        m_Protocol.close();
        //m_Protocol.sendUserAction({});
        return;
    }
    if (turnInfo.m_TurnInfo == START_TURN || turnInfo.m_TurnInfo == END_GAME) {
        m_GameUpdates.push(turnInfo);
    }
    if (id != m_IdPlayer) {
        if (turnInfo.m_TurnInfo == START_TURN) {
            std::cout << "Player " << id << " started turn" << std::endl;
        } else if (turnInfo.m_TurnInfo == END_TURN) {
            std::cout << "Player " << id << " ended turn" << std::endl;
        }
        return;
    }
    if (turnInfo.m_TurnInfo == START_TURN) {
        m_EventSender.setItsMyTurn(true);
    } else if (turnInfo.m_TurnInfo == END_TURN) {
        m_EventSender.setItsMyTurn(false);
    } else {
        throw std::runtime_error("Invalid turn info");
    }
}
