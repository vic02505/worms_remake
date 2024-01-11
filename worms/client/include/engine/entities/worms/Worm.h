#pragma once

#include <SDL_render.h>
#include <iostream>
#include "messages/sprites/SpritesEnum.h"
#include "utils/WorldScale.h"
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "Skins.h"
#include "engine/entities/effects/EffectSkins.h"
#include "messages/server/GameUpdate.h"
#include "messages/user_actions/ActionType.h"
#include "messages/user_actions/WeaponID.h"
#include <filesystem>
#include <unordered_map>
#include <vector>
#include <utility>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#define HEALTH_WIDTH_FONT 30
#define HEALTH_HEIGHT_FONT 30
#define HEALTH_RECT_Y 20
#define NAME_RECT_Y 35
#define NAME_WIDTH_FONT 35
#define NAME_HEIGHT_FONT 30

class Worm {
 private:
    int m_IdPlayer;
    std::string m_PlayerName;
    SpritesEnum m_CurrentSprite;
    Direction m_Dir;
    std::vector<SDL_Rect > m_DieRects;
    GameUpdate m_LastUpdate{};
    SDL_Rect m_NameDestRect{};
    SDL_Rect m_HealthDestRect{};
    int m_Health;
    Mix_Chunk* m_StepSound;
    Mix_Chunk *m_JumpSound;
    Mix_Chunk *m_DieSound;

 public:
    SDL_Renderer* m_Renderer;
    std::unordered_map<SpritesEnum, std::unique_ptr<Animation>> m_SpritesMap;
    float m_WormXPosition;
    float m_WormYPosition;
    float m_Widht;
    float m_Height;

private:
    std::unique_ptr<Animation> getWaccuseAnimation(const std::string& spritePath, BlendMode blendMode, int frames,
                                                   int distanceBetweenFrames,
                                                   int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                                                   int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY);

    void renderInfoWorm();

 public:
    Worm(int idPlayer, std::string playerName, SDL_Renderer *renderer, float posX, float posY, float d, float d1);

    void init();
    void update(double elapsedSeconds, const GameUpdate& gameUpdate);
    void update(double elapsedSeconds);
    void render();

    ~Worm();

    void updateBateAttack(double elapsedSeconds, const GameUpdate &gameUpdate);
    void UpdateBazooka(double elapsedSeconds, const GameUpdate &gameUpdate);

    void updateBateHit(double seconds, const GameUpdate &update);

    void playSound();

    void updateHealth(const uint8_t &health);
};