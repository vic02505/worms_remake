#pragma once

#include "../IWormInstruction.h"
#include "messages/user_actions/ActionType.h"

class WormStopMove : public IWormInstruction {
public:
    explicit WormStopMove(int idPlayer);
    void execute(WWorm* worm) override;
    ~WormStopMove() override = default;
};