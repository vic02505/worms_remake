#include "world/entities/action_animations/types/SActionAttack.h"

SActionAttack::SActionAttack(uint8_t weaponId) {
    m_WeaponId = WeaponID(weaponId);
}

SpritesEnum SActionAttack::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock> &startTime) {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    switch (m_WeaponId) {
        case WeaponID::AXE:
            if (elapsedSeconds.count() > 1.0) {
                m_CurrentSprite = SPRITE_WACCUSE_IDLE;
                break;
            }
            m_CurrentSprite = SPRITE_ATTACK_AXE;
            break;
        case NO_WEAPON:
            m_CurrentSprite = SPRITE_WACCUSE_IDLE;
            break;
        case BATE:
            if (elapsedSeconds.count() > 1.0) {
                m_CurrentSprite = SPRITE_WACCUSE_IDLE;
                break;
            }
            m_CurrentSprite = SPRITE_ATTACK_BATE;
            break;
        default:
            break;
    }
    return m_CurrentSprite;
}
