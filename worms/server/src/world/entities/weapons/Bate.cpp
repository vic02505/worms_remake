#include "world/entities/weapons/impl/Bate.h"

Bate::Bate() {
    this->m_WeaponId = WeaponID::BATE;
    this->distance = 3.0f;
}

void Bate::attack(WWorm *attacker, WWorm* attacked, uint8_t force) {
    attacker->getActionToAnimation()->resetAnimation();
    attacker->getActionToAnimation()->setAction(ActionType::ATTACK, m_WeaponId);
    if (attacked->getId() == attacker->getId()) {
        return;
    }
    float mForce;
    switch (force) {
        case LOW:
            mForce = 70;
            break;
        case MEDIUM:
            mForce = 150;
            break;
        case HIGH:
            mForce = 250;
            break;
        default:
            mForce = 70;
            break;
    }
    std::cout << "Bate attack. FORCE : [" << mForce << "]." << std::endl;
    float distanceBetween = b2Distance(attacker->getPosition(), attacked->getPosition());
    if (distanceBetween > distance) {
        return;
    }

    float angle = attacker->getWeaponAngle();
    float xForce = cos(angle);
    float yForce = sin(angle);
    attacker->getDirection() == Direction::LEFT ? xForce *= -1 : xForce *= 1;
    b2Vec2 forceVector = mForce * b2Vec2(xForce, yForce);   //VALORES OK PARA UN GOLPE MEDIANO / ALTO
    std::cout << "Force vector: " << forceVector.x << " " << forceVector.y << std::endl;
    attacker->setIsAttacking(true);
    attacked->getBody()->ApplyLinearImpulseToCenter(forceVector, true);
    attacked->receiveDamage(30);
}

void Bate::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Bate::getWeaponId() const {
    return this->m_WeaponId;
}
