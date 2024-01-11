#pragma once

#include "Weapon.h"
#include "world/entities/weapons/impl/Axe.h"
#include "world/entities/weapons/impl/Bate.h"
#include "world/entities/weapons/impl/Bazooka.h"
#include "world/entities/WWorm.h"

class Weapon;
class WeaponFactory {
public:
    WeaponFactory() = default;
    Weapon* createWeapon(WeaponID weaponId, WWorm* attacker);

    ~WeaponFactory() = default;

    WeaponFactory(const WeaponFactory&) = default;
    WeaponFactory& operator=(const WeaponFactory&) = default;
    WeaponFactory(WeaponFactory&&) noexcept = default;
    WeaponFactory& operator=(WeaponFactory&&) noexcept = default;
};