#include "world/instructions/impl/WormNone.h"

WormNone::WormNone(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormNone::execute(WWorm *worm) {
    // Do nothing
}
