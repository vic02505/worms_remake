#include "world/instructions/impl/WormSetWeapon.h"

WormSetWeapon::WormSetWeapon(int idPlayer, WeaponID weapon) {
    this->setIdPlayer(idPlayer);
    m_Weapon = weapon;
    m_ActionType = ActionType::SET_WEAPON;
}

void WormSetWeapon::execute(WWorm *worm) {
    worm->setWeapon(m_Weapon, m_ActionType);
}
