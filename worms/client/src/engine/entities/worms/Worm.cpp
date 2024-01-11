#include "engine/entities/worms/Worm.h"

Worm::Worm(int idPlayer, std::string playerName, SDL_Renderer *renderer, float posX, float posY, float width,
           float height) : m_IdPlayer(idPlayer), m_PlayerName(std::move(playerName)), m_Renderer(renderer),
           m_WormXPosition(posX), m_WormYPosition(posY), m_Widht(WorldScale::toPixel(width)),
           m_Height(WorldScale::toPixel(height)) {}

void Worm::init() {
        m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_IDLE;
        WaccuseIdle waccuseIdle;
        WaccuseWalk waccuseWalk;
        WaccuseJumping waccuseJumping;
        WaccuseDie waccuseDie;
        WaccuseGettingDamage waccuseGettingDamage;
        GraveSkin waccuseGrave;
        SettingAxe waSettingAxe;
        HasAxe waHasAxe;
        SavingAxe waSavingAxe;
        SettingBate waSettingBate;
        HasBate wHasBate;
        SavingBate wSavingBate;
        AttackAxe wAttackAxe;
        BatePositiveAngles batePositiveAngles;
        BateNegativeAngles bateNegativeAngles;
        NormalAttackBate wNormalAttackBate;
        PositiveAnglesAttackBate wPositiveAnglesAttackBate;
        NegativeAnglesAttackBate wNegativeAnglesAttackBate;
        SettingBazooka wSettingBazooka;
        HasBazooka wHasBazooka;
        SavingBazooka wSavingBazooka;

        NegativeAnglesBazooka wNegativeAnglesBazooka;
        PositiveAnglesBazooka wPositiveAnglesBazooka;
        SettingTeleport settingTeleport;
        HasTeleport hasTeleport;
        UseTeleport useTeleport;

        SetGreenGranade wSetGreenGranade;
        HasGreenGranade wHasGreenGranade;
        SaveGreenGranade wSaveGreenGranade;


    SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
        };

    m_NameDestRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)) - NAME_RECT_Y,
                static_cast<int>(NAME_WIDTH_FONT), static_cast<int>(NAME_HEIGHT_FONT)
        };

    m_HealthDestRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)) - HEALTH_RECT_Y,
                static_cast<int>(HEALTH_WIDTH_FONT), static_cast<int>(HEALTH_HEIGHT_FONT)
        };


        m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_GREEN_GRANADE, getWaccuseAnimation(
                wSetGreenGranade.spritePath,
                wSetGreenGranade.blendMode,
                wSetGreenGranade.frames,
                wSetGreenGranade.distanceBetweenFrames,
                wSetGreenGranade.frameWidth,
                wSetGreenGranade.frameHeight,
                wSetGreenGranade.duration,
                wSetGreenGranade.srcRect,
                wSetGreenGranade.initYSprite,
                destRect,
                wSetGreenGranade.deltaPosX,
                wSetGreenGranade.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_GREEN_GRANADE, getWaccuseAnimation(
                wHasGreenGranade.spritePath,
                wHasGreenGranade.blendMode,
                wHasGreenGranade.frames,
                wHasGreenGranade.distanceBetweenFrames,
                wHasGreenGranade.frameWidth,
                wHasGreenGranade.frameHeight,
                wHasGreenGranade.duration,
                wHasGreenGranade.srcRect,
                wHasGreenGranade.initYSprite,
                destRect,
                wHasGreenGranade.deltaPosX,
                wHasGreenGranade.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_GREEN_GRANADE, getWaccuseAnimation(
                wSaveGreenGranade.spritePath,
                wSaveGreenGranade.blendMode,
                wSaveGreenGranade.frames,
                wSaveGreenGranade.distanceBetweenFrames,
                wSaveGreenGranade.frameWidth,
                wSaveGreenGranade.frameHeight,
                wSaveGreenGranade.duration,
                wSaveGreenGranade.srcRect,
                wSaveGreenGranade.initYSprite,
                destRect,
                wSaveGreenGranade.deltaPosX,
                wSaveGreenGranade.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_BAZOOKA, getWaccuseAnimation(
            wSettingBazooka.spritePath,
            wSettingBazooka.blendMode,
            wSettingBazooka.frames,
            wSettingBazooka.distanceBetweenFrames,
            wSettingBazooka.frameWidth,
            wSettingBazooka.frameHeight,
            wSettingBazooka.duration,
            wSettingBazooka.srcRect,
            wSettingBazooka.initYSprite,
            destRect,
            wSettingBazooka.deltaPosX,
            wSettingBazooka.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_BAZOOKA, getWaccuseAnimation(
            wHasBazooka.spritePath,
            wHasBazooka.blendMode,
            wHasBazooka.frames,
            wHasBazooka.distanceBetweenFrames,
            wHasBazooka.frameWidth,
            wHasBazooka.frameHeight,
            wHasBazooka.duration,
            wHasBazooka.srcRect,
            wHasBazooka.initYSprite,
            destRect,
            wHasBazooka.deltaPosX,
            wHasBazooka.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_BAZOOKA, getWaccuseAnimation(
            wSavingBazooka.spritePath,
            wSavingBazooka.blendMode,
            wSavingBazooka.frames,
            wSavingBazooka.distanceBetweenFrames,
            wSavingBazooka.frameWidth,
            wSavingBazooka.frameHeight,
            wSavingBazooka.duration,
            wSavingBazooka.srcRect,
            wSavingBazooka.initYSprite,
            destRect,
            wSavingBazooka.deltaPosX,
            wSavingBazooka.deltaPosY));


        m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_IDLE, getWaccuseAnimation(
                waccuseIdle.spritePath,
                waccuseIdle.blendMode,
                waccuseIdle.frames,
                waccuseIdle.distanceBetweenFrames,
                waccuseIdle.frameWidth,
                waccuseIdle.frameHeight,
                waccuseIdle.duration,
                waccuseIdle.srcRect,
                waccuseIdle.initYSprite,
                destRect,
                waccuseIdle.deltaPosX,
                waccuseIdle.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_WALK, getWaccuseAnimation(
                waccuseWalk.spritePath,
                waccuseWalk.blendMode,
                waccuseWalk.frames,
                waccuseWalk.distanceBetweenFrames,
                waccuseWalk.frameWidth,
                waccuseWalk.frameHeight,
                waccuseWalk.duration,
                waccuseWalk.srcRect,
                waccuseWalk.initYSprite,
                destRect,
                waccuseWalk.deltaPosX,
                waccuseWalk.deltaPosY));
        m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_AXE, getWaccuseAnimation(
                waSettingAxe.spritePath,
                waSettingAxe.blendMode,
                waSettingAxe.frames,
                waSettingAxe.distanceBetweenFrames,
                waSettingAxe.frameWidth,
                waSettingAxe.frameHeight,
                waSettingAxe.duration,
                waSettingAxe.srcRect,
                waSettingAxe.initYSprite,
                destRect,
                waSettingAxe.deltaPosX,
                waSettingAxe.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_AXE, getWaccuseAnimation(
            waHasAxe.spritePath,
            waHasAxe.blendMode,
            waHasAxe.frames,
            waHasAxe.distanceBetweenFrames,
            waHasAxe.frameWidth,
            waHasAxe.frameHeight,
            waHasAxe.duration,
            waHasAxe.srcRect,
            waHasAxe.initYSprite,
            destRect,
            waHasAxe.deltaPosX,
            waHasAxe.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_AXE, getWaccuseAnimation(
            waSavingAxe.spritePath,
            waSavingAxe.blendMode,
            waSavingAxe.frames,
            waSavingAxe.distanceBetweenFrames,
            waSavingAxe.frameWidth,
            waSavingAxe.frameHeight,
            waSavingAxe.duration,
            waSavingAxe.srcRect,
            waSavingAxe.initYSprite,
            destRect,
            waSavingAxe.deltaPosX,
            waSavingAxe.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_JUMPING, getWaccuseAnimation(
            waccuseJumping.spritePath,
            waccuseJumping.blendMode,
            waccuseJumping.frames,
            waccuseJumping.distanceBetweenFrames,
            waccuseJumping.frameWidth,
            waccuseJumping.frameHeight,
            waccuseJumping.duration,
            waccuseJumping.srcRect,
            waccuseJumping.initYSprite,
            destRect,
            waccuseJumping.deltaPosX,
            waccuseJumping.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_DIE, getWaccuseAnimation(
            waccuseDie.spritePath,
            waccuseDie.blendMode,
            waccuseDie.frames,
            waccuseDie.distanceBetweenFrames,
            waccuseDie.frameWidth,
            waccuseDie.frameHeight,
            waccuseDie.duration,
            waccuseDie.srcRect,
            waccuseDie.initYSprite,
            destRect,
            waccuseDie.deltaPosX,
            waccuseDie.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_GETTING_DAMAGE, getWaccuseAnimation(
            waccuseGettingDamage.spritePath,
            waccuseGettingDamage.blendMode,
            waccuseGettingDamage.frames,
            waccuseGettingDamage.distanceBetweenFrames,
            waccuseGettingDamage.frameWidth,
            waccuseGettingDamage.frameHeight,
            waccuseGettingDamage.duration,
            waccuseGettingDamage.srcRect,
            waccuseGettingDamage.initYSprite,
            destRect,
            waccuseGettingDamage.deltaPosX,
            waccuseGettingDamage.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_GRAVE, getWaccuseAnimation(
            waccuseGrave.spritePath,
            waccuseGrave.blendMode,
            waccuseGrave.frames,
            waccuseGrave.distanceBetweenFrames,
            waccuseGrave.frameWidth,
            waccuseGrave.frameHeight,
            waccuseGrave.duration,
            waccuseGrave.srcRect,
            waccuseGrave.initYSprite,
            destRect,
            waccuseGrave.deltaPosX,
            waccuseGrave.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_BATE, getWaccuseAnimation(
            waSettingBate.spritePath,
            waSettingBate.blendMode,
            waSettingBate.frames,
            waSettingBate.distanceBetweenFrames,
            waSettingBate.frameWidth,
            waSettingBate.frameHeight,
            waSettingBate.duration,
            waSettingBate.srcRect,
            waSettingBate.initYSprite,
            destRect,
            waSettingBate.deltaPosX,
            waSettingBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_BATE, getWaccuseAnimation(
            wSavingBate.spritePath,
            wSavingBate.blendMode,
            wSavingBate.frames,
            wSavingBate.distanceBetweenFrames,
            wSavingBate.frameWidth,
            wSavingBate.frameHeight,
            wSavingBate.duration,
            wSavingBate.srcRect,
            wSavingBate.initYSprite,
            destRect,
            wSavingBate.deltaPosX,
            wSavingBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_ATTACK_AXE, getWaccuseAnimation(
            wAttackAxe.spritePath,
            wAttackAxe.blendMode,
            wAttackAxe.frames,
            wAttackAxe.distanceBetweenFrames,
            wAttackAxe.frameWidth,
            wAttackAxe.frameHeight,
            wAttackAxe.duration,
            wAttackAxe.srcRect,
            wAttackAxe.initYSprite,
            destRect,
            wAttackAxe.deltaPosX,
            wAttackAxe.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_BATE_INIT_POSITION, getWaccuseAnimation(
            wHasBate.spritePath,
            wHasBate.blendMode,
            wHasBate.frames,
            wHasBate.distanceBetweenFrames,
            wHasBate.frameWidth,
            wHasBate.frameHeight,
            wHasBate.duration,
            wHasBate.srcRect,
            wHasBate.initYSprite,
            destRect,
            wHasBate.deltaPosX,
            wHasBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_BATE_POSITIVE_ANGLES, getWaccuseAnimation(
            batePositiveAngles.spritePath,
            batePositiveAngles.blendMode,
            batePositiveAngles.frames,
            batePositiveAngles.distanceBetweenFrames,
            batePositiveAngles.frameWidth,
            batePositiveAngles.frameHeight,
            batePositiveAngles.duration,
            batePositiveAngles.srcRect,
            batePositiveAngles.initYSprite,
            destRect,
            batePositiveAngles.deltaPosX,
            batePositiveAngles.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_BATE_NEGATIVE_ANGLES, getWaccuseAnimation(
            bateNegativeAngles.spritePath,
            bateNegativeAngles.blendMode,
            bateNegativeAngles.frames,
            bateNegativeAngles.distanceBetweenFrames,
            bateNegativeAngles.frameWidth,
            bateNegativeAngles.frameHeight,
            bateNegativeAngles.duration,
            bateNegativeAngles.srcRect,
            bateNegativeAngles.initYSprite,
            destRect,
            bateNegativeAngles.deltaPosX,
            bateNegativeAngles.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_ATTACK_BATE_NORMAL, getWaccuseAnimation(
            wNormalAttackBate.spritePath,
            wNormalAttackBate.blendMode,
            wNormalAttackBate.frames,
            wNormalAttackBate.distanceBetweenFrames,
            wNormalAttackBate.frameWidth,
            wNormalAttackBate.frameHeight,
            wNormalAttackBate.duration,
            wNormalAttackBate.srcRect,
            wNormalAttackBate.initYSprite,
            destRect,
            wNormalAttackBate.deltaPosX,
            wNormalAttackBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_ATTACK_BATE_POSITIVE_ANGLES, getWaccuseAnimation(
            wPositiveAnglesAttackBate.spritePath,
            wPositiveAnglesAttackBate.blendMode,
            wPositiveAnglesAttackBate.frames,
            wPositiveAnglesAttackBate.distanceBetweenFrames,
            wPositiveAnglesAttackBate.frameWidth,
            wPositiveAnglesAttackBate.frameHeight,
            wPositiveAnglesAttackBate.duration,
            wPositiveAnglesAttackBate.srcRect,
            wPositiveAnglesAttackBate.initYSprite,
            destRect,
            wPositiveAnglesAttackBate.deltaPosX,
            wPositiveAnglesAttackBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_ATTACK_BATE_NEGATIVE_ANGLES, getWaccuseAnimation(
            wNegativeAnglesAttackBate.spritePath,
            wNegativeAnglesAttackBate.blendMode,
            wNegativeAnglesAttackBate.frames,
            wNegativeAnglesAttackBate.distanceBetweenFrames,
            wNegativeAnglesAttackBate.frameWidth,
            wNegativeAnglesAttackBate.frameHeight,
            wNegativeAnglesAttackBate.duration,
            wNegativeAnglesAttackBate.srcRect,
            wNegativeAnglesAttackBate.initYSprite,
            destRect,
            wNegativeAnglesAttackBate.deltaPosX,
            wNegativeAnglesAttackBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_POSITIVE_ANGLE_BAZOOKA, getWaccuseAnimation(
            wPositiveAnglesBazooka.spritePath,
            wPositiveAnglesBazooka.blendMode,
            wPositiveAnglesBazooka.frames,
            wPositiveAnglesBazooka.distanceBetweenFrames,
            wPositiveAnglesBazooka.frameWidth,
            wPositiveAnglesBazooka.frameHeight,
            wPositiveAnglesBazooka.duration,
            wPositiveAnglesBazooka.srcRect,
            wPositiveAnglesBazooka.initYSprite,
            destRect,
            wPositiveAnglesBazooka.deltaPosX,
            wPositiveAnglesBazooka.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_NEGATIVE_ANGLE_BAZOOKA, getWaccuseAnimation(
            wNegativeAnglesBazooka.spritePath,
            wNegativeAnglesBazooka.blendMode,
            wNegativeAnglesBazooka.frames,
            wNegativeAnglesBazooka.distanceBetweenFrames,
            wNegativeAnglesBazooka.frameWidth,
            wNegativeAnglesBazooka.frameHeight,
            wNegativeAnglesBazooka.duration,
            wNegativeAnglesBazooka.srcRect,
            wNegativeAnglesBazooka.initYSprite,
            destRect,
            wNegativeAnglesBazooka.deltaPosX,
            wNegativeAnglesBazooka.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_TELEPORT, getWaccuseAnimation(
            settingTeleport.spritePath,
            settingTeleport.blendMode,
            settingTeleport.frames,
            settingTeleport.distanceBetweenFrames,
            settingTeleport.frameWidth,
            settingTeleport.frameHeight,
            settingTeleport.duration,
            settingTeleport.srcRect,
            settingTeleport.initYSprite,
            destRect,
            settingTeleport.deltaPosX,
            settingTeleport.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_TELEPORT, getWaccuseAnimation(
            hasTeleport.spritePath,
            hasTeleport.blendMode,
            hasTeleport.frames,
            hasTeleport.distanceBetweenFrames,
            hasTeleport.frameWidth,
            hasTeleport.frameHeight,
            hasTeleport.duration,
            hasTeleport.srcRect,
            hasTeleport.initYSprite,
            destRect,
            hasTeleport.deltaPosX,
            hasTeleport.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_USE_TELEPORTER, getWaccuseAnimation(
            useTeleport.spritePath,
            useTeleport.blendMode,
            useTeleport.frames,
            useTeleport.distanceBetweenFrames,
            useTeleport.frameWidth,
            useTeleport.frameHeight,
            useTeleport.duration,
            useTeleport.srcRect,
            useTeleport.initYSprite,
            destRect,
            useTeleport.deltaPosX,
            useTeleport.deltaPosY));

    for (auto& sprite : m_SpritesMap) {
        sprite.second->init();
    }

    m_StepSound = Mix_LoadWAV(std::filesystem::current_path().concat("/resources/Music/worm-walk.mp3").c_str());
    m_JumpSound = Mix_LoadWAV(std::filesystem::current_path().concat("/resources/Music/worm-jump.mp3").c_str());
    m_DieSound = Mix_LoadWAV(std::filesystem::current_path().concat("/resources/Music/worm-dead.mp3").c_str());
    if (m_StepSound == NULL || m_JumpSound == NULL || m_DieSound == NULL) {
        std::cout << "Error loading sound: " << Mix_GetError() << std::endl;
    }
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    m_LastUpdate = gameUpdate;
    if (gameUpdate.m_CurrentSprite == SpritesEnum::SPRITE_HAS_BATE) {
//    m_Health = static_cast<int>(gameUpdate.m_Health);
        updateBateAttack(elapsedSeconds, gameUpdate);
    } else if (gameUpdate.m_CurrentSprite == SpritesEnum::SPRITE_ATTACK_BATE) {
//        m_Health = static_cast<int>(gameUpdate.m_Health);
        updateBateHit(elapsedSeconds, gameUpdate);
    } else if (gameUpdate.m_CurrentSprite == SpritesEnum::SPRITE_HAS_BAZOOKA) {
//        m_Health = static_cast<int>(gameUpdate.m_Health);
        UpdateBazooka(elapsedSeconds, gameUpdate);
    } else {
        m_CurrentSprite = gameUpdate.m_CurrentSprite;
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
        playSound();
    }

    if (gameUpdate.m_Movement != GameAction::INVALID_ACTION) {
//        m_Health = static_cast<int>(gameUpdate.m_Health);
        m_Dir = gameUpdate.m_Dir;
        Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
        float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, anim->getDeltaPosX());
        float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, anim->getDeltaPosY());
        anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                           anim->getFrameHeight()});
        m_WormXPosition = gameUpdate.x_pos;
        m_WormYPosition = gameUpdate.y_pos;
        m_HealthDestRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)) - HEALTH_RECT_Y,
                static_cast<int>(HEALTH_WIDTH_FONT), static_cast<int>(HEALTH_HEIGHT_FONT)
        };
        m_NameDestRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)) - NAME_RECT_Y,
                static_cast<int>(NAME_WIDTH_FONT), static_cast<int>(NAME_HEIGHT_FONT)
        };
    }
}


void Worm::UpdateBazooka(double elapsedSeconds, const GameUpdate &gameUpdate) {

    HasBazooka hasBazooka;
    float angle = gameUpdate.m_WeaponAngle;
    int pickedFrame = -1;

    if (angle > 0) {
        pickedFrame = static_cast<int>(angle / hasBazooka.unitAngle);
        m_CurrentSprite = SpritesEnum::SPRITE_POSITIVE_ANGLE_BAZOOKA;
    } else if (angle < 0) {
        float normalizedAngle = angle + 90;
        pickedFrame = static_cast<int>(normalizedAngle / 6);
        m_CurrentSprite = SpritesEnum::SPRITE_NEGATIVE_ANGLE_BAZOOKA;
    } else {
        m_CurrentSprite = SpritesEnum::SPRITE_HAS_BAZOOKA;
    }

    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds, pickedFrame);
}

void Worm::updateBateAttack(double elapsedSeconds, const GameUpdate &gameUpdate) {
    HasBate hasBate;
    float angle = gameUpdate.m_WeaponAngle;
    int pickedFrame = -1;
    if (angle > 0) {
        pickedFrame = static_cast<int>(angle / hasBate.unitAngle);
        m_CurrentSprite = SpritesEnum::SPRITE_HAS_BATE_POSITIVE_ANGLES;
    } else if (angle < 0) {
        float normalizedAngle = angle + 90;
        pickedFrame = static_cast<int>(normalizedAngle / 6);
        m_CurrentSprite = SpritesEnum::SPRITE_HAS_BATE_NEGATIVE_ANGLES;
    } else {
        m_CurrentSprite = SpritesEnum::SPRITE_HAS_BATE_INIT_POSITION;
    }
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds, pickedFrame);
}

void Worm::render() {
    bool isFlip = true;
    if (m_Dir == Direction::LEFT) {
        isFlip = false;
    }
    bool bateAttack = m_LastUpdate.m_CurrentSprite == SPRITE_ATTACK_BATE;
    std::unique_ptr<Animation> &anim = m_SpritesMap.at(m_CurrentSprite);
    if (bateAttack) {
        m_Dir == Direction::LEFT ? anim->setDestRect({anim->getDestRect().x - 20, anim->getDestRect().y, anim->getFrameWidth(), anim->getFrameHeight()})
                                 : anim->setDestRect({anim->getDestRect().x + 20, anim->getDestRect().y, anim->getFrameWidth(), anim->getFrameHeight()});
        anim->render(isFlip);
    } else {
        anim->render(isFlip);
    }
    renderInfoWorm();
}

std::unique_ptr<Animation> Worm::getWaccuseAnimation(const std::string& spritePath, BlendMode blendMode, int frames,
                                                     int distanceBetweenFrames,
                                                     int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                                                     int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY) {
    return std::unique_ptr<Animation>(new Animation(spritePath,m_Renderer, blendMode, frames, distanceBetweenFrames,
                                                    frameWidth, frameHeight, duration, srcRect, initYSprite, destRect,
                                                    deltaPosX, deltaPosY));
}

void Worm::update(double elapsedSeconds) {
    Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
    float tempX = WorldScale::worldToPixelX(m_WormXPosition, anim->getDeltaPosX());
    float tempY = WorldScale::worldToPixelY(m_WormYPosition, anim->getDeltaPosY());
    anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                       anim->getFrameHeight()});
    if (m_LastUpdate.m_CurrentSprite == SPRITE_HAS_BATE) {
        updateBateAttack(elapsedSeconds, m_LastUpdate);
    } else if (m_LastUpdate.m_CurrentSprite == SPRITE_HAS_BAZOOKA) {
        UpdateBazooka(elapsedSeconds, m_LastUpdate);
    } else {
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
    }
}

void Worm::updateBateHit(double seconds, const GameUpdate &update) {
    HasBate hasBate;
    NormalAttackBate normalAttackBate;
    float angle = update.m_WeaponAngle;
    int pickedFrame = -1;
    if (angle > 0) {
        pickedFrame = static_cast<int>(angle / hasBate.unitAngle);
        m_CurrentSprite = SpritesEnum::SPRITE_ATTACK_BATE_POSITIVE_ANGLES;
    } else if (angle < 0) {
        float normalizedAngle = angle + 90;
        pickedFrame = static_cast<int>(normalizedAngle / 6);
        m_CurrentSprite = SpritesEnum::SPRITE_ATTACK_BATE_NEGATIVE_ANGLES;
    } else {
        m_CurrentSprite = SpritesEnum::SPRITE_ATTACK_BATE_NORMAL;
    }
    m_SpritesMap.at(m_CurrentSprite)->update(seconds, pickedFrame);
}

void Worm::renderInfoWorm() {
    TTF_Font* font = TTF_OpenFont(std::filesystem::current_path()
            .concat("/resources/Fonts/Dhurjati-Regular.ttf").c_str(), 30);

    SDL_Color textColor = {0, 0, 0, 255};

    SDL_Surface* playerNameSurface = TTF_RenderText_Solid(font, m_PlayerName.c_str(), textColor);
    SDL_Texture* playerNameTexture = SDL_CreateTextureFromSurface(m_Renderer, playerNameSurface);

    SDL_RenderCopy(m_Renderer, playerNameTexture, NULL, &m_NameDestRect);

    std::string healthStr = std::to_string(m_Health);
    SDL_Surface* healthSurface = TTF_RenderText_Solid(font, healthStr.c_str(), textColor);
    SDL_Texture* healthTexture = SDL_CreateTextureFromSurface(m_Renderer, healthSurface);

    SDL_RenderCopy(m_Renderer, healthTexture, NULL, &m_HealthDestRect);

    SDL_FreeSurface(playerNameSurface);
    SDL_DestroyTexture(playerNameTexture);
    SDL_FreeSurface(healthSurface);
    SDL_DestroyTexture(healthTexture);
    TTF_CloseFont(font);
}

Worm::~Worm() {
    std::cout << "Destroing Worm" << std::endl;
    for (auto& sprite : m_SpritesMap) {
        sprite.second = nullptr;
    }
    Mix_FreeChunk(m_StepSound);
}

void Worm::playSound() {
    switch (m_CurrentSprite) {
        case SPRITE_WALK:
            Mix_PlayChannel(-1, m_StepSound, 0);
            break;
        case SPRITE_JUMPING:
            Mix_PlayChannel(-1, m_JumpSound, 0);
            break;
        case SPRITE_WACCUSE_DIE:
            Mix_PlayChannel(-1, m_DieSound, 0);
            break;
        default:
            Mix_HaltChannel(-1);
            break;
    }
}

void Worm::updateHealth(const uint8_t &health) {
    m_Health = health;
}

