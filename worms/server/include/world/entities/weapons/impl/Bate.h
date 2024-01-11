#pragma once

#include "world/entities/weapons/Weapon.h"
#include "../../../../../../Box2D/include/box2d/box2d.h"
#include "world/entities/WWorm.h"

class WWorm;
class Bate : public Weapon {
private:
    int damage;
    float distance;
public:
    Bate();
    void attack(WWorm* attacker, WWorm* attacked, uint8_t force) override;

    void setWeaponId(WeaponID weaponId) override;
    WeaponID getWeaponId() const override;

    ~Bate() override = default;
};