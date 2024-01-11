#include "world/entities/action_animations/AnimationFactory.h"

SpriteAnimations *AnimationFactory::createAnimation(const ActionType& actionType, uint8_t param1, uint8_t param2) {
    switch (actionType) {
        case ActionType::MOVE:
            return new SActionMove();
        case ActionType::JUMP:
            return new SActionJump();
        case ActionType::SET_WEAPON:
            return new SActionWeapon(param1, param2);
        case ActionType::UNSET_WEAPON:
            return new SActionWeapon(param1, param2);
        case ActionType::DYING:
            return new SActionDeath();
        case ActionType::ATTACKED:
            return new SActionAttacked();
        case ActionType::ATTACK:
            return new SActionAttack(param1);
        case ActionType::NONE:
            return new SActionIdle();
        case ActionType::STOP_MOVE:
            return new SActionIdle();
        case ActionType::SET_TOOL:
            return new SActionTool(param1);
        case ActionType::USE_TOOL:
            return new SActionUseTool(param1);
        default:
            return new SActionIdle();
    }
}

SpriteAnimations *AnimationFactory::createDeathAnimation() {
    return new SActionDeath();
}
