#include "world/entities/action_animations/types/SActionIdle.h"

SActionIdle::SActionIdle() {
    this->m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_IDLE;
}

SpritesEnum SActionIdle::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) {
    return this->m_CurrentSprite;
}

