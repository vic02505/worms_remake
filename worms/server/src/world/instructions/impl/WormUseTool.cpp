#include "world/instructions/impl/WormUseTool.h"

WormUseTool::WormUseTool(int idPlayer, float param1, float param2) {
    this->m_ActionType = ActionType::USE_TOOL;
    this->m_IdPlayer = idPlayer;
    this->m_Param1 = param1;
    this->m_Param2 = param2;
}

void WormUseTool::execute(WWorm *worm) {
    worm->useTool(m_Param1, m_Param2);
}
