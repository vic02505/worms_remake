#include "world/entities/action_animations/types/SActionWeapon.h"

SActionWeapon::SActionWeapon(uint8_t weaponType, uint8_t actionWeaponType) {
    m_WeaponType = WeaponID(weaponType);
    m_ActionWeaponType = ActionWeaponType(actionWeaponType);
    switch (m_WeaponType) {
        case WeaponID::AXE:
            m_Sequence = buildAxeSequence();
            break;
        case WeaponID::BATE:
            m_Sequence = buildBateSequence();
            break;
        case WeaponID::BAZOOKA:
            m_Sequence = buildBazookaSequence();
            break;
        case WeaponID::GRANADE:
            m_Sequence = buildGreenGranadeSequence();
            break;
        default:
            m_Sequence = buildAxeSequence();
            break;
    }
}

SpritesEnum SActionWeapon::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    switch (m_ActionWeaponType) {
        case ActionWeaponType::ACTION_WEAPON_TYPE_SET_WEAPON:
            if (elapsedSeconds.count() > 0.5) {
                m_CurrentSprite = m_Sequence.hasWeapon;
                break;
            }
            m_CurrentSprite = m_Sequence.setWeapon;
            break;
        case ActionWeaponType::ACTION_WEAPON_TYPE_HAS_WEAPON:
            m_CurrentSprite = m_Sequence.hasWeapon;
            break;
        case ActionWeaponType::ACTION_WEAPON_TYPE_UNSET_WEAPON:
            if (elapsedSeconds.count() > 0.5) {
                m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_IDLE;
                break;
            }
            m_CurrentSprite = m_Sequence.saveWeapon;
        default:
            break;
    }
    return m_CurrentSprite;
}

Squence SActionWeapon::buildAxeSequence() {
    Squence sequence{};
    sequence.setWeapon = SpritesEnum::SPRITE_SETTING_AXE;
    sequence.hasWeapon = SpritesEnum::SPRITE_HAS_AXE;
    return sequence;
}

Squence SActionWeapon::buildBateSequence() {
    Squence sequence{};
    sequence.setWeapon = SpritesEnum::SPRITE_SETTING_BATE;
    sequence.hasWeapon = SpritesEnum::SPRITE_HAS_BATE;
    return sequence;
}

Squence SActionWeapon::buildBazookaSequence() {
    Squence sequence{};
    sequence.setWeapon = SpritesEnum::SPRITE_SETTING_BAZOOKA;
    sequence.hasWeapon = SpritesEnum::SPRITE_HAS_BAZOOKA;
    sequence.saveWeapon = SpritesEnum::SPRITE_SAVING_BAZOOKA;
    return sequence;
}

Squence SActionWeapon::buildGreenGranadeSequence() {
    Squence sequence{};
    sequence.setWeapon = SpritesEnum::SPRITE_SETTING_GREEN_GRANADE;
    sequence.hasWeapon = SpritesEnum::SPRITE_HAS_GREEN_GRANADE;
    sequence.saveWeapon = SpritesEnum::SPRITE_SAVING_GREEN_GRANADE;
    return sequence;
}
