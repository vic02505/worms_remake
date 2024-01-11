#include "world/entities/action_animations/types/SActionMove.h"

SActionMove::SActionMove() {
    m_CurrentSprite = SpritesEnum::SPRITE_WALK;
}

SpritesEnum SActionMove::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) {
    return m_CurrentSprite;
}

