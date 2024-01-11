
#include "engine/entities/projectiles/projectile.h"

Projectile::Projectile(SDL_Renderer *renderer): 
        m_Renderer(renderer), m_ProjectileXPosition(0),
         m_ProjectileYPosition(0), m_Widht(0), m_Height(WorldScale::toPixel(0)) {}

void Projectile::init(){

    GreenGranade wGreenGranada;
    BazookaMissile wBazookaMissile;
    ProjectileExplotion wProjectileExplotion;

    SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_ProjectileXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_ProjectileYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
    };

    m_SpritesMap.emplace(SpritesEnum::SPRITE_GREEN_GRANADE, getProjectileAnimation(
                wGreenGranada.spritePath,
                wGreenGranada.blendMode,
                wGreenGranada.frames,
                wGreenGranada.distanceBetweenFrames,
                wGreenGranada.frameWidth,
                wGreenGranada.frameHeight,
                wGreenGranada.duration,
                wGreenGranada.srcRect,
                wGreenGranada.initYSprite,
                destRect,
                wGreenGranada.deltaPosX,
                wGreenGranada.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_BAZOOKA_MISSILE, getProjectileAnimation(
                wBazookaMissile.spritePath,
                wBazookaMissile.blendMode,
                wBazookaMissile.frames,
                wBazookaMissile.distanceBetweenFrames,
                wBazookaMissile.frameWidth,
                wBazookaMissile.frameHeight,
                wBazookaMissile.duration,
                wBazookaMissile.srcRect,
                wBazookaMissile.initYSprite,
                destRect,
                wBazookaMissile.deltaPosX,
                wBazookaMissile.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_EXPLOTION, getProjectileAnimation(
            wProjectileExplotion.spritePath,
            wProjectileExplotion.blendMode,
            wProjectileExplotion.frames,
            wProjectileExplotion.distanceBetweenFrames,
            wProjectileExplotion.frameWidth,
            wProjectileExplotion.frameHeight,
            wProjectileExplotion.duration,
            wProjectileExplotion.srcRect,
            wProjectileExplotion.initYSprite,
            destRect,
            wProjectileExplotion.deltaPosX,
            wProjectileExplotion.deltaPosY));



    for (auto& sprite : m_SpritesMap) {
        sprite.second->init();
    }

}

void Projectile::update(double elapsedSeconds, const GameUpdate& gameUpdate){
    m_CurrentSprite = gameUpdate.m_CurrentSprite;
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);

    if(m_CurrentSprite == SpritesEnum::SPRITE_EXPLOTION){
        //HOLAAA
    }

    if (gameUpdate.m_Movement != GameAction::INVALID_ACTION) {
        m_Dir = gameUpdate.m_Dir;
        Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
        float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, anim->getDeltaPosX());
        float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, anim->getDeltaPosY());
        anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                           anim->getFrameHeight()});
        m_ProjectileXPosition = gameUpdate.x_pos;
        m_ProjectileYPosition = gameUpdate.y_pos;
    }

}

void Projectile::update(double elapsedSeconds){

     Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
    float tempX = WorldScale::worldToPixelX(m_ProjectileXPosition, anim->getDeltaPosX());
    float tempY = WorldScale::worldToPixelY(m_ProjectileYPosition, anim->getDeltaPosY());
    anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                       anim->getFrameHeight()});
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds); 
}

void Projectile::render(){

 bool isFlip = true;
    if (m_Dir == Direction::LEFT) {
        isFlip = false;
    }

    m_SpritesMap.at(m_CurrentSprite)->render(isFlip);
}

std::unique_ptr<Animation> Projectile::getProjectileAnimation(const std::string& spritePath, BlendMode blendMode, int frames,
                                                  int distanceBetweenFrames,
                                                  int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                                                  int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY){

    return std::unique_ptr<Animation>(new Animation(spritePath,m_Renderer, blendMode, frames, distanceBetweenFrames,
                                                    frameWidth, frameHeight, duration, srcRect, initYSprite, destRect,
                                                    deltaPosX, deltaPosY));

}