#include "world/instructions/impl/WormJump.h"

WormJump::WormJump(int idPlayer) {
    this->setIdPlayer(idPlayer);
    this->m_ActionType = ActionType::JUMP;
}

void WormJump::execute(WWorm *worm) {
    worm->jump();
}
