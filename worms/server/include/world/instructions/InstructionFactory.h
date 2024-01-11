#pragma once

#include "IWormInstruction.h"
#include "messages/user_actions/UserAction.h"
#include "world/instructions/impl/WormMove.h"
#include "world/instructions/impl/WormStopMove.h"
#include "world/instructions/impl/WormJump.h"
#include "world/instructions/impl/WormNone.h"
#include "world/instructions/impl/WormAttack.h"
#include "world/instructions/impl/WormSetWeapon.h"
#include "world/instructions/impl/WormUnSetWeapon.h"
#include "world/instructions/impl/WormIncreaseAngle.h"
#include "world/instructions/impl/WormDecreaseAngle.h"
#include "world/instructions/impl/WormSelfKill.h"
#include "world/instructions/impl/WormSetTool.h"
#include "world/instructions/impl/WormUseTool.h"
#include <iostream>

class InstructionFactory {
public:
    InstructionFactory() = default;

    IWormInstruction* createInstruction(UserAction userAction);
    ~InstructionFactory() = default;
    InstructionFactory(const InstructionFactory&) = default;
    InstructionFactory& operator=(const InstructionFactory&) = default;
    InstructionFactory(InstructionFactory&&) noexcept = default;
    InstructionFactory& operator=(InstructionFactory&&) noexcept = default;
};