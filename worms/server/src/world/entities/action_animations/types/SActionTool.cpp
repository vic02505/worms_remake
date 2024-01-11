#include "world/entities/action_animations/types/SActionTool.h"


SActionTool::SActionTool(uint8_t tool) {
    m_Tool = ToolID(tool);
    m_ActionType = ToolType::ACTION_TYPE_SET_TOOL;
    switch (m_Tool) {
        case TELEPORTER:
            m_Sequence = buildTeleportSequence();
            break;
        default:
            m_Sequence = buildTeleportSequence();
            break;
    }
}

SpritesEnum SActionTool::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock> &startTime) {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    switch (m_ActionType) {
        case ToolType::ACTION_TYPE_SET_TOOL:
            if (elapsedSeconds.count() > 0.5) {
                m_CurrentSprite = m_Sequence.hasTool;
                m_ActionType = ToolType::ACTION_TYPE_HAS_TOOL;
                break;
            }
            m_CurrentSprite = m_Sequence.setTool;
            break;
        case ToolType::ACTION_TYPE_HAS_TOOL:
            m_CurrentSprite = m_Sequence.hasTool;
            break;
        default:
            break;
    }
    return m_CurrentSprite;
}

ToolSquence SActionTool::buildTeleportSequence() {
    ToolSquence sequence{};
    sequence.setTool = SpritesEnum::SPRITE_SETTING_TELEPORT;
    sequence.hasTool = SpritesEnum::SPRITE_HAS_TELEPORT;
    return sequence;
}
