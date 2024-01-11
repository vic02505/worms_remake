#pragma once

#include "../../../../../Box2D/include/box2d/box2d.h"
#include "messages/user_actions/WeaponID.h"

class WWorm;
class Weapon {
protected:
    WeaponID m_WeaponId = WeaponID::NO_WEAPON;
public:
    virtual void attack(WWorm* attacker, WWorm* attacked, uint8_t force) = 0;

    virtual void setWeaponId(WeaponID weaponId) = 0;

    virtual WeaponID getWeaponId() const = 0;

    virtual ~Weapon() = default;
};