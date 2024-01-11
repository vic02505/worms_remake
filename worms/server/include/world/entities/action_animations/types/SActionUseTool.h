#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"
#include "messages/user_actions/ToolID.h"

class SActionUseTool : public SpriteAnimations {
private:
    ToolID m_ToolId;
public:
    explicit SActionUseTool(uint8_t toolId);
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) override;
};