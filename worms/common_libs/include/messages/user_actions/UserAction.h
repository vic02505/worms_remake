#pragma once

#include "ActionType.h"
#include "WeaponID.h"

class UserAction {
private:
    ActionType m_Action;
    int m_IdPlayer;
    uint8_t m_Param1;
    uint8_t m_Param2;
    float m_Param3;
    float m_Param4;
public:
    UserAction(ActionType action, int idPlayer, uint8_t param1, uint8_t param2);
    UserAction(ActionType action, int idPlayer, uint8_t param1);
    UserAction(ActionType action, int idPlayer);
    UserAction(ActionType action, int idPlayer, float param3, float param4);
    UserAction();

    [[nodiscard]] ActionType getAction() const;
    [[nodiscard]] int getIdPlayer() const;
    [[nodiscard]] uint8_t getParam1() const;
    [[nodiscard]] uint8_t getParam2() const;
    [[nodiscard]] float getParam3() const;
    [[nodiscard]] float getParam4() const;

    void setAction(ActionType actionType);
    void setIdPlayer(int idPlayer);
    void setParam1(uint8_t param1);
    void setParam2(uint8_t param2);
    void setParam3(float param3);
    void setParam4(float param4);


    ~UserAction() = default;

    UserAction(const UserAction&) = default;
};