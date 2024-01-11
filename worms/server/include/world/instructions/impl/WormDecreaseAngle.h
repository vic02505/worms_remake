#pragma once

#include "world/instructions/IWormInstruction.h"


class WormDecreaseAngle : public IWormInstruction {
public:
    explicit WormDecreaseAngle(int idPlayer);
    void execute(WWorm* worm) override;
    ~WormDecreaseAngle() override = default;
};