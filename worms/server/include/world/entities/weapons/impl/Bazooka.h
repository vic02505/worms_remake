#pragma once

#include "world/entities/weapons/Weapon.h"
#include "world/entities/WWorm.h"
#include "world/entities/WProyectile.h"
#include <memory>

class WWorm;
class WProyectile;
class Bazooka : public Weapon {
private:
    int damage;
    float distance;

    WProyectile* projectile;

public:
    Bazooka(WWorm* attacker);
    void attack(WWorm* attacker, WWorm* attacked, uint8_t force) override;


    void setWeaponId(WeaponID weaponId) override;
    WeaponID getWeaponId() const override;

    ~Bazooka() override = default;
};
