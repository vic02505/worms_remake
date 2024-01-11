#include "world/entities/weapons/impl/Bazooka.h"

Bazooka::Bazooka(WWorm* attacker) : damage(50), distance(2.0f) {
    this->m_WeaponId = WeaponID::BAZOOKA;
    projectile = new WProyectile(attacker->getWorld(), attacker);
}

void Bazooka::attack(WWorm *attacker, WWorm *attacked, uint8_t force) {
    attacker->getActionToAnimation()->resetAnimation();
    attacker->getActionToAnimation()->setAction(ActionType::ATTACK, m_WeaponId, 0);


    if (attacked->getId() == attacker->getId()) {
        return;
    }


    float angle = attacker->getWeaponAngle();
    b2Body* projectileBody = projectile->getBody();


    b2Vec2 initialForce(cos(angle)*projectileBody->GetMass()*9.8, sin(angle)*projectileBody->GetMass()*9.8);

    if (attacker->getDirection() == Direction::LEFT){
        initialForce.x *= -1;
        initialForce.y *= -1;
    }

    projectileBody->ApplyLinearImpulseToCenter(initialForce, true);

    //b2Vec2 projectilePosition = projectileBody->GetPosition();


/*
    if((projectilePosition - attacked->getPosition()).Length() < 3) {
        attacker->setIsAttacking(true);
        attacked->receiveDamage(damage);
    }
*/

    attacker->tieneProyectil = true;
    attacker->proyectil = std::move(projectile);
}

void Bazooka::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Bazooka::getWeaponId() const {
    return this->m_WeaponId;
}

