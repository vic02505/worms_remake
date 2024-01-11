#include "world/instructions/impl/WormStopMove.h"

WormStopMove::WormStopMove(int idPlayer) {
    setIdPlayer(idPlayer);
    m_ActionType = ActionType::STOP_MOVE;
}

void WormStopMove::execute(WWorm *worm) {
    worm->stopMove();
}
