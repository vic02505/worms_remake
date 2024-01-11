#include "world/entities/weapons/WeaponFactory.h"


Weapon *WeaponFactory::createWeapon(WeaponID weaponId,  WWorm* attacker) {
    switch (weaponId) {
        case WeaponID::AXE:
            return new Axe();
        case WeaponID::BATE:
            return new Bate();
        case WeaponID::BAZOOKA:
            return new Bazooka(attacker);
        default:
            return new Axe();
    }
}
