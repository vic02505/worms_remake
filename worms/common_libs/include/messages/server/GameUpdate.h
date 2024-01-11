#pragma once

#include "GameActionEnum.h"
#include "../user_actions/WeaponID.h"
#include "messages/user_actions/ActionType.h"
#include "messages/sprites/SpritesEnum.h"
#include "messages/user_actions/ToolID.h"
#include <unordered_set>
#include <string>

struct GameUpdate {
    uint8_t player_id;
    std::string m_PlayerName;
    float x_pos;
    float y_pos;
    float width;
    float height;
    double m_TimeDuration;

    GameAction m_Movement;
    WeaponID m_Weapon;
    bool m_IsAttacking;
    uint8_t m_Health;
    Direction  m_Dir;
    GameAction m_SelfCondition;
    float m_VelocityX;
    float m_VelocityY;
    SpritesEnum m_CurrentSprite;
    GameAction m_TurnInfo;
    float m_WeaponAngle;
    double m_SecondsPerTurn;
    bool m_InfoWorm;
    ToolID m_Tool;

    GameUpdate() : player_id(0xFF), x_pos(0), y_pos(0), width(0.0f), height(0.0f), m_TimeDuration(0.0f),
    m_Movement(INVALID_ACTION), m_Weapon(NO_WEAPON), m_IsAttacking(false), m_Health(0xFF), m_Dir(Direction::RIGHT),
    m_SelfCondition(GameAction::WORM_NONE), m_VelocityX(0.0f), m_VelocityY(0.0f), m_CurrentSprite(SPRITE_INVALID),
    m_TurnInfo(INVALID_ACTION), m_WeaponAngle(0.0f), m_SecondsPerTurn(0), m_InfoWorm(false), m_Tool(NO_TOOL) {}

    bool operator!=(const GameUpdate& other) const;
};
