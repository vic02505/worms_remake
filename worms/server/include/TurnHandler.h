#pragma once

#include <chrono>
#include <vector>
#include <iostream>
#include <map>

class TurnHandler {
private:
    int idCurrentPlayer;
    std::map<int, int> m_IdPlayers;
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    double m_MaxTurnSeconds;
    bool m_TestMode;
    bool m_EndGame;
    int m_WinnerId;

public:
    explicit TurnHandler(int idPlayer, std::vector<int> players, bool testMode = false);

    bool isValidTurn();
    void nextTurn(const std::vector<int>& wormsRemovedIds);
    [[nodiscard]] int getCurrentPlayer() const;

    ~TurnHandler() = default;
    TurnHandler(const TurnHandler&) = delete;
    TurnHandler(TurnHandler&& other) = delete;


    [[nodiscard]] double getSecondsPerTurn() const;

    [[nodiscard]] bool isEndGame() const;

    [[nodiscard]] int getWinnerId() const;
};

