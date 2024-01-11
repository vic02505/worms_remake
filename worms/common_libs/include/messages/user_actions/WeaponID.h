#pragma once

enum WeaponID : uint8_t {
    AXE = 0X00,
    NO_WEAPON = 0X01,
    BATE = 0X02,
    BAZOOKA = 0X03,
    GRANADE = 0x04
};

enum BateForce : uint8_t {
    LOW = 0X00,
    MEDIUM = 0X01,
    HIGH = 0X02
};

enum BatePotency {
    LOW_POTENCY = 0,
    MEDIUM_POTENCY = 2,
    HIGH_POTENCY = 6
};