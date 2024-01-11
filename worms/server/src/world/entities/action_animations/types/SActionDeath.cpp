#include "world/entities/action_animations/types/SActionDeath.h"

SActionDeath::SActionDeath() {
    this->m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_DIE;
}

SpritesEnum SActionDeath::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock> &startTime) {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    if (m_CurrentSprite == SPRITE_WACCUSE_DIE) {
        if (elapsedSeconds.count() > 1.0) {
            m_CurrentSprite = SPRITE_WACCUSE_GRAVE;
        }
    }
    return m_CurrentSprite;
}
