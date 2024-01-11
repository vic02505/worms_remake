#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"

class SActionDeath : public SpriteAnimations {
 public:
    SActionDeath();
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) override;
};