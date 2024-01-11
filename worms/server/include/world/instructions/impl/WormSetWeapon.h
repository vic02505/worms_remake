#pragma once

#include "world/instructions/IWormInstruction.h"
#include "messages/user_actions/WeaponID.h"

class WormSetWeapon : public IWormInstruction {
private:
    WeaponID m_Weapon;
public:
    explicit WormSetWeapon(int idPlayer, WeaponID weapon);
    void execute(WWorm* worm) override;
    ~WormSetWeapon() override = default;
};