#include "world/instructions/impl/WormSelfKill.h"

WormSelfKill::WormSelfKill(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormSelfKill::execute(WWorm *worm) {
    worm->receiveDamage(worm->getHealth());
}

