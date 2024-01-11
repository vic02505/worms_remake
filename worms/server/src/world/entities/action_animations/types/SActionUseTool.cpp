#include "world/entities/action_animations/types/SActionUseTool.h"

SActionUseTool::SActionUseTool(uint8_t toolId) {
    this->m_ToolId = ToolID(toolId);
}

SpritesEnum SActionUseTool::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock> &startTime) {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    switch (m_ToolId) {
        case ToolID::TELEPORTER:
            if (elapsedSeconds.count() > 2.0) {
                m_CurrentSprite = SPRITE_WACCUSE_IDLE;
                break;
            }
            m_CurrentSprite = SPRITE_USE_TELEPORTER;
            break;
        case ToolID::NO_TOOL:
            m_CurrentSprite = SPRITE_WACCUSE_IDLE;
            break;
    }
    return m_CurrentSprite;
}

