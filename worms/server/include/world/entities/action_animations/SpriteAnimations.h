#pragma once

#include "messages/sprites/SpritesEnum.h"
#include <chrono>

class SpriteAnimations {
protected:
    SpritesEnum m_CurrentSprite = SPRITE_WACCUSE_IDLE;
public:
    virtual ~SpriteAnimations() = default;
    [[nodiscard]] virtual SpritesEnum
    getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) = 0;
};