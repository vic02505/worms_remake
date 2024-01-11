#pragma once

#include "../IWormInstruction.h"
#include "messages/user_actions/ActionType.h"

class WormJump : public IWormInstruction {
public:
    WormJump(int idPlayer);
    void execute(WWorm* worm) override;
    ~WormJump() override = default;
};