#pragma once

#include "world/instructions/IWormInstruction.h"

class WormIncreaseAngle : public IWormInstruction {
private:
    int param1;
public:
    explicit WormIncreaseAngle(int idPlayer);
    void execute(WWorm* worm) override;
    ~WormIncreaseAngle() override = default;
};