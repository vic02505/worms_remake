#include "world/instructions/impl/WormDecreaseAngle.h"

WormDecreaseAngle::WormDecreaseAngle(int idPlayer) {
    this->setIdPlayer(idPlayer);
    this->m_ActionType = ActionType::DECREASE_ANGLE;
}

void WormDecreaseAngle::execute(WWorm *worm) {
    float radianAngle = worm->getWeaponAngle();
    float gradAngle = radianAngle * 180 / b2_pi;
    if (gradAngle - 5.0f < -90.0f) {
        gradAngle = -90.0f;
    } else {
        gradAngle -= 5.0f;
    }
    radianAngle = gradAngle * b2_pi / 180;
    worm->setWeaponAngle(radianAngle, false, m_ActionType);
}

