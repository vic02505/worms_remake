#include "world/instructions/impl/WormSetTool.h"

WormSetTool::WormSetTool(int idPlayer, uint8_t toolID) {
    this->setIdPlayer(idPlayer);
    this->m_ToolID = ToolID(toolID);
}

void WormSetTool::execute(WWorm *worm) {
    worm->setTool(this->m_ToolID);
}
