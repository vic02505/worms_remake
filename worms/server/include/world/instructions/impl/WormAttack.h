#pragma once

#include "world/instructions/IWormInstruction.h"
#include "messages/user_actions/ActionType.h"

class WormAttack : public IWormInstruction {
private:
    uint8_t m_Param1;
public:
    explicit WormAttack(int idPlayer, uint8_t param1);
    void execute(WWorm* worm) override;
    ~WormAttack() override = default;
};