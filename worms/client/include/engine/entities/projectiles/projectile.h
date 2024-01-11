#ifndef PROJECTILE_H
#define PROJECTILE_H


#include <SDL_render.h>
#include <iostream>
#include "messages/sprites/SpritesEnum.h"
#include "utils/WorldScale.h"
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "engine/entities/worms/Skins.h"
#include "engine/entities/effects/EffectSkins.h"
#include "messages/server/GameUpdate.h"
#include "messages/user_actions/ActionType.h"
#include "messages/user_actions/WeaponID.h"
#include <filesystem>
#include <unordered_map>
#include <vector>


class Projectile{
private:
    SpritesEnum m_CurrentSprite;
    Direction m_Dir;

public:
    SDL_Renderer* m_Renderer;
    std::unordered_map<SpritesEnum, std::unique_ptr<Animation>> m_SpritesMap;
    float m_ProjectileXPosition;
    float m_ProjectileYPosition;
    float m_Widht;
    float m_Height;

    bool is_launched{false};
    bool exploded{false};

private:
    std::unique_ptr<Animation> getProjectileAnimation(const std::string& spritePath, BlendMode blendMode, int frames,
                                                   int distanceBetweenFrames,
                                                   int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                                                   int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY) ;


public:
    Projectile(SDL_Renderer *renderer);

    void init();
    void update(double elapsedSeconds, const GameUpdate& gameUpdate);
    void update(double elapsedSeconds);
    void render();

    ~Projectile() = default;

};

#endif
