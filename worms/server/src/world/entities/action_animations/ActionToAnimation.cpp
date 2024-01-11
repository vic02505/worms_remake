#include "world/entities/action_animations/ActionToAnimation.h"
#include "world/entities/WWorm.h"

ActionToAnimation::ActionToAnimation() : m_Action(ActionType::NONE), m_StartTime(std::chrono::system_clock::now()) {}

SpritesEnum ActionToAnimation::getCurrentSprite(WWorm* worm) {
    SpriteAnimations* animation = AnimationFactory::createAnimation(m_Action, m_Param1, m_Param2);
    SpritesEnum sprite = animation->getCurrentSprite(m_StartTime);
    delete animation;
    if (sprite == SPRITE_JUMPING && worm->getVelocity().y == 0) {
        sprite = SPRITE_WACCUSE_IDLE;
    }
    m_CurrentSprite = sprite;
    return m_CurrentSprite;
}

void ActionToAnimation::resetAnimation() {
    this->m_Action = ActionType::NONE;
    this->m_StartTime = std::chrono::system_clock::now();
}

void ActionToAnimation::setAction(ActionType action, uint8_t param1, uint8_t param2) {
    this->m_Action = action;
    m_Param1 = param1;
    m_Param2 = param2;
}

SpritesEnum ActionToAnimation::getCurrentSprite() const {
    return m_CurrentSprite;
}


