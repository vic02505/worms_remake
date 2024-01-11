#pragma once

#include "../IWormInstruction.h"
#include <iostream>

class WormNone : public IWormInstruction {
public:
    explicit WormNone(int idPlayer);
    void execute(WWorm* worm) override;
};