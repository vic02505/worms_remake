#include "../include/Server.h"

Server::Server(const char* port): socket(port), m_KeepRunning(true) {}

void Server::acceptConnection() {
    Socket peer = socket.accept();
    m_Clients.emplace_back(std::move(peer), &m_Games);
    m_Clients.back().start();
}

void Server::run() {
    try {
        while (m_KeepRunning) {
            acceptConnection();
            reapDead();
        }
        killAll();
    } catch (const LibError& e) {
        if (!m_KeepRunning.load()) {
            killAll();
            return;
        }
        unexpectedError();
    } catch (...) {
        unexpectedError();
    }
}

void Server::reapDead() {
    for (auto it = m_Clients.begin(); it != m_Clients.end();) {
        if (it->isDead()) {
            it->join();
            m_Games.removePlayer(it->getIdGame(), it->getIdPlayer());
            it = m_Clients.erase(it);
        } else {
            ++it;
        }
    }
}

void Server::stop() {
    m_KeepRunning.store(false);
    this->socket.shutdown(SHUT_RD);
    this->socket.close();
}

void Server::killAll() {
    for (auto it = m_Clients.begin(); it != m_Clients.end();) {
        if (!it->isDead()) {
            it->kill();
        }
        it->join();
        it = m_Clients.erase(it);
    }
}

void Server::unexpectedError() {
    stop();
    killAll();
    throw UnExpectedException("Unexpected error");
}

