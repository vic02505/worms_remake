#pragma once

#include "SpriteAnimations.h"
#include "messages/user_actions/ActionType.h"
#include "world/entities/action_animations/types/SActionMove.h"
#include "world/entities/action_animations/types/SActionIdle.h"
#include "world/entities/action_animations/types/SActionJump.h"
#include "world/entities/action_animations/types/SActionWeapon.h"
#include "world/entities/action_animations/types/SActionDeath.h"
#include "world/entities/action_animations/types/SActionAttacked.h"
#include "world/entities/action_animations/types/SActionAttack.h"
#include "world/entities/action_animations/types/SActionTool.h"
#include "world/entities/action_animations/types/SActionUseTool.h"


class AnimationFactory {
public:
    AnimationFactory() = default;
    static SpriteAnimations* createAnimation(const ActionType& actionType, uint8_t param1 = 0, uint8_t param2 = 0);
    static SpriteAnimations* createDeathAnimation();

    ~AnimationFactory() = default;

    AnimationFactory(const AnimationFactory&) = default;
    AnimationFactory& operator=(const AnimationFactory&) = default;
    AnimationFactory(AnimationFactory&&) noexcept = default;
    AnimationFactory& operator=(AnimationFactory&&) noexcept = default;
};