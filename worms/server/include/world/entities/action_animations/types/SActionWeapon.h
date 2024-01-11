#pragma once

#include <cstdint>
#include <chrono>
#include "world/entities/action_animations/SpriteAnimations.h"
#include "messages/user_actions/WeaponID.h"

enum ActionWeaponType : uint8_t {
    ACTION_WEAPON_TYPE_SET_WEAPON = 0x00,
    ACTION_WEAPON_TYPE_HAS_WEAPON = 0x01,
    ACTION_WEAPON_TYPE_UNSET_WEAPON = 0x02
};

struct Squence {
    SpritesEnum setWeapon;
    SpritesEnum hasWeapon;
    SpritesEnum saveWeapon;
};
class SActionWeapon : public SpriteAnimations {
private:
    WeaponID m_WeaponType;
    uint8_t  m_ActionWeaponType;
    Squence m_Sequence{};
    Squence buildAxeSequence();
    Squence buildBateSequence();
    Squence buildBazookaSequence();
    Squence buildGreenGranadeSequence();
public:
    SActionWeapon(uint8_t weaponType, uint8_t actionType);
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) override;
};