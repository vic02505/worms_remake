#include "world/instructions/impl/WormIncreaseAngle.h"

WormIncreaseAngle::WormIncreaseAngle(int idPlayer) {
    this->setIdPlayer(idPlayer);
    this->m_ActionType = ActionType::INCREASE_ANGLE;
}

void WormIncreaseAngle::execute(WWorm *worm) {
    float radianAngle = worm->getWeaponAngle();
    float gradAngle = radianAngle * 180.0f / b2_pi;
    gradAngle = gradAngle + 6.0f;
    if (gradAngle > 90.0f) {
        gradAngle = 90.0f;
    }
    float angle = gradAngle * b2_pi / 180.0f;
    worm->setWeaponAngle(angle, true, m_ActionType);
}
