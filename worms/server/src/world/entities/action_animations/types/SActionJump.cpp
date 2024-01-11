#include "world/entities/action_animations/types/SActionJump.h"

SActionJump::SActionJump() {
    m_CurrentSprite = SpritesEnum::SPRITE_JUMPING;
}

SpritesEnum SActionJump::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) {
    return m_CurrentSprite;
}
