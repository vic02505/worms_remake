#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"
#include <chrono>

class SActionIdle : public SpriteAnimations {
 public:
    SActionIdle();
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) override;
};