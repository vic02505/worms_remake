#include "world/instructions/impl/WormMove.h"

WormMove::WormMove(int idPlayer, Direction m_Dir) : m_Dir(m_Dir) {
    setIdPlayer(idPlayer);
    m_ActionType = ActionType::MOVE;
}

void WormMove::execute(WWorm* worm) {
    worm->move(m_Dir);
}


