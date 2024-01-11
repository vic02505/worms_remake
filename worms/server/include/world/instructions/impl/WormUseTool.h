#pragma once


#include "world/instructions/IWormInstruction.h"
#include "messages/user_actions/ActionType.h"

class WormUseTool : public IWormInstruction {
private:
    float m_Param1;
    float m_Param2;
public:
    explicit WormUseTool(int idPlayer, float param1, float param2);
    void execute(WWorm* worm) override;
    ~WormUseTool() override = default;
};