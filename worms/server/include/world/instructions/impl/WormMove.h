#pragma once

#include "../IWormInstruction.h"
#include "messages/user_actions/ActionType.h"


class WormMove : public IWormInstruction {
private:
    Direction m_Dir;
public:
    WormMove(int idPlayer, Direction m_Dir);
    void execute(WWorm* world) override;
    ~WormMove() override = default;
};
