#pragma once

#include <cstdint>
#include "messages/user_actions/ToolID.h"
#include "messages/sprites/SpritesEnum.h"
#include "world/entities/action_animations/SpriteAnimations.h"
#include <chrono>

enum ToolType : uint8_t  {
    ACTION_TYPE_SET_TOOL = 0x00,
    ACTION_TYPE_HAS_TOOL = 0x01
};

struct ToolSquence {
    SpritesEnum setTool;
    SpritesEnum hasTool;
};

class SActionTool : public SpriteAnimations {
private:
    ToolID m_Tool;
    uint8_t m_ActionType{};
    ToolSquence m_Sequence{};
    ToolSquence buildTeleportSequence();
public:
    SActionTool(uint8_t tool);
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) override;
};