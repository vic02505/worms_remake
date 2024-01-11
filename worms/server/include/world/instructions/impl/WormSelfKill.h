#pragma once

#include "../IWormInstruction.h"
#include <iostream>

class WormSelfKill : public IWormInstruction {
    public:
    explicit WormSelfKill(int idPlayer);
    void execute(WWorm* worm) override;
};