#pragma once

#include "world/instructions/IWormInstruction.h"
#include "messages/user_actions/ToolID.h"

class WormSetTool : public IWormInstruction {
private:
    ToolID m_ToolID;
    public:
    explicit WormSetTool(int idPlayer, uint8_t toolID);
    void execute(WWorm* worm) override;
};