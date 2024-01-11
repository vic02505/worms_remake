#pragma once

#include "world/instructions/IWormInstruction.h"

class WormUnSetWeapon : public IWormInstruction {
public:
    explicit WormUnSetWeapon(int idPlayer);
    void execute(WWorm* worm) override;
    ~WormUnSetWeapon() override = default;
};