#include "../include/TurnHandler.h"


TurnHandler::TurnHandler(int idPlayer, std::vector<int> idPlayers, bool testMode) :
    idCurrentPlayer(idPlayer), m_StartTime(std::chrono::system_clock::now()), m_MaxTurnSeconds(60),
    m_TestMode(testMode), m_EndGame(false), m_WinnerId(-1) {
    m_IdPlayers = std::map<int, int>();
    for (int i = 0; i < static_cast<int>(idPlayers.size()); i++) {
        m_IdPlayers.insert(std::pair<int, int>(i, idPlayers.at(i)));
    }
}

bool TurnHandler::isValidTurn() {
    std::chrono::duration<double> elapsedSeconds = std::chrono::system_clock::now() - m_StartTime;
    return elapsedSeconds.count() < m_MaxTurnSeconds;
}

void TurnHandler::nextTurn(const std::vector<int>& wormsRemovedIds) {
    for (auto& wormRemovedId : wormsRemovedIds) {
        m_IdPlayers.erase(wormRemovedId);
    }

    if (m_IdPlayers.size() == 1) {
        m_EndGame = true;
        m_WinnerId = m_IdPlayers.begin()->second;
        return;
    }

    auto it = m_IdPlayers.upper_bound(idCurrentPlayer);
    if (it == m_IdPlayers.end()) {
        idCurrentPlayer = m_IdPlayers.begin()->second;
    } else {
        idCurrentPlayer = it->second;
    }

    m_StartTime = std::chrono::system_clock::now();
}

int TurnHandler::getCurrentPlayer() const {
    return idCurrentPlayer;
}

double TurnHandler::getSecondsPerTurn() const {
    return m_MaxTurnSeconds;
}

bool TurnHandler::isEndGame() const {
    return m_EndGame;
}

int TurnHandler::getWinnerId() const {
    return m_WinnerId;
}



