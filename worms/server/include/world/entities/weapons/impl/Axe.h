#pragma once

#include "world/entities/weapons/Weapon.h"
#include "world/entities/WWorm.h"

class Axe : public Weapon {
private:
    int damage;
    float distance;
public:
    Axe();
    void attack(WWorm* attacker, WWorm* attacked, uint8_t force) override;

    void setWeaponId(WeaponID weaponId) override;
    WeaponID getWeaponId() const override;

    ~Axe() override = default;
};