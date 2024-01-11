#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"

class SActionAttacked : public SpriteAnimations {
 public:
    SActionAttacked();
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) override;
};