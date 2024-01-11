#include "../include/ClientSender.h"


ClientSender::ClientSender(Protocol& protocol, ProtectedQueue<GameUpdate>* selfQueue, int idPlayer) :
        m_Protocol(protocol), m_SelfQueue(selfQueue), m_IdPlayer(idPlayer), m_KeepRunning(true) {}

void ClientSender::run() {
    try {
        while (m_KeepRunning) {
            auto update = m_SelfQueue->pop();
            if (update.player_id == 0xFF) {
                continue;
            }
            m_Protocol.sendGameUpdate(update);
            if (update.m_TurnInfo == END_GAME) {
                m_KeepRunning.store(false);
                m_Protocol.shutdown(SHUT_RDWR);
                m_Protocol.close();
            }
        }
    } catch (const LibError& e) {
        m_KeepRunning.store(false);
        if(! m_Protocol.isClosed() ) {
        m_Protocol.shutdown(SHUT_RDWR);
        }
    } catch (const ClosedQueue& cqe) {
        m_KeepRunning.store(false);
        if(! m_Protocol.isClosed() ) {
            m_Protocol.shutdown(SHUT_RDWR);
        }
    } catch (...) {
        std::cout << "Error en ClientSender" << std::endl;
    }
}

void ClientSender::stop() {
    m_KeepRunning.store(false);
    if(!m_SelfQueue->isClosed()) {
        m_SelfQueue->push(GameUpdate {});
    }
    if( !m_Protocol.isClosed()) {
        m_Protocol.close();
    }
}

void ClientSender::setPlayerId(int idPlayer) {
    this->m_IdPlayer = idPlayer;
}

bool ClientSender::isRunning() const {
    return m_KeepRunning.load();
}
