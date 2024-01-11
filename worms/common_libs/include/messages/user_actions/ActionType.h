#pragma once

#include <cstdint>

enum ActionType : uint8_t {
    MOVE = 0X00,
    STOP_MOVE = 0X01,
    JUMP = 0X02,
    NONE = 0X03,
    ATTACK = 0X04,
    STOP_ATTACK = 0X05,
    SET_WEAPON = 0X06,
    UNSET_WEAPON = 0X07,
    DECREASE_ANGLE = 0X08,
    INCREASE_ANGLE = 0X09,
    DYING = 0X0A,
    SELF_KILL = 0X0B,
    SET_TOOL = 0X0C,
    USE_TOOL = 0X0D,
    ATTACKED = 0X0B
};


enum Direction : uint8_t {
    LEFT = 0X00,
    RIGHT = 0X01,
    NONE_DIR = 0X02
};

inline Direction operator!(Direction dir) {
    return dir == LEFT ? RIGHT : LEFT;
}
