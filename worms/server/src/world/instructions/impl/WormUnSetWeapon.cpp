#include "world/instructions/impl/WormUnSetWeapon.h"

WormUnSetWeapon::WormUnSetWeapon(int idPlayer) {
    this->setIdPlayer(idPlayer);
    m_ActionType = ActionType::UNSET_WEAPON;
}

void WormUnSetWeapon::execute(WWorm *worm) {
    worm->unSetWeapon();
}
