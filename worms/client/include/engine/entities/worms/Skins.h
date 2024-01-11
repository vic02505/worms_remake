#pragma once

#include <string>
#include <SDL_rect.h>
#include "engine/graphics/Texture.h"
#include <filesystem>

/* DOCUMENTACION
 * DeltaPosX y DeltaPosY corresponden a la correccion para mostrar el sprite segun la dimension de este ya que
 * existen sprites distintos, y habria que modificar el cuerpo del World para poder mandar desde el servidor el width y height
 * Y asi modelar usando WorldScale::toPixel(w o h) y renderizar el gusano segun las dimensaiones que esta tomando en el World
 * En este proyecto, a priori se utiliza un Worm dinamico pero que no cambia sus dimensiones a lo largo del juego*/
struct WaccuseIdle {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waccuse.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 22, 26};
    int initYSprite = 17;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct WaccuseWalk {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wwalk.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 9;
    int distanceBetweenFrames = 60;
    int frameWidth = 30;
    int frameHeight = 44;
    float duration = 0.7f;
    SDL_Rect srcRect = {11, 14, 28, 29};
    int initYSprite = 14;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};


struct WaccuseAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxebk2.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 7;
    int distanceBetweenFrames = 104;
    int frameWidth = 47;
    int frameHeight = 47;
    float duration = 2.0f;
    SDL_Rect srcRect = {39, 26, 41, 39};
    int initYSprite = 26;
    float deltaPosX = 47.0f;
    float deltaPosY = 51.0f;
};

struct SettingAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxelnk.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 15;
    int distanceBetweenFrames = 104;
    int frameWidth = 47;
    int frameHeight = 47;
    float duration = 2.0f;
    SDL_Rect srcRect = {39, 26, 41, 39};
    int initYSprite = 26;
    float deltaPosX = 47.0f;
    float deltaPosY = 51.0f;
};

struct HasAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxelk2.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 23;
    int distanceBetweenFrames = 104;
    int frameWidth = 47;
    int frameHeight = 47;
    float duration = 2.0f;
    SDL_Rect srcRect = {39, 26, 41, 39};
    int initYSprite = 26;
    float deltaPosX = 47.0f;
    float deltaPosY = 51.0f;
};

struct SavingAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxebk2.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 15;
    int distanceBetweenFrames = 104;
    int frameWidth = 47;
    int frameHeight = 47;
    float duration = 2.0f;
    SDL_Rect srcRect = {39, 26, 41, 39};
    int initYSprite = 26;
    float deltaPosX = 47.0f;
    float deltaPosY = 51.0f;
};

struct WaccuseJumping {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waccuseu.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 18, 30};
    int initYSprite = 17;
    float deltaPosX = 25.6f; // WIDTH WORLD WORM * 2 * 25.6
    float deltaPosY = 40.96f; // HEIGHT WORLD WORM * 2 * 25.6
};

struct WaccuseDie {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wdie.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 60;
    int distanceBetweenFrames = 60;
    int frameWidth = 47;
    int frameHeight = 53;
    float duration = 1.0f;
    SDL_Rect srcRect = {1, 7, 38, 40};
    int initYSprite = 7;
    float deltaPosX = 30.0f;
    float deltaPosY = 52.0f;
};

struct WaccuseGettingDamage {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wpbrtlk.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 1.0f;
    SDL_Rect srcRect = {20, 17, 22, 26};
    int initYSprite = 17;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct SettingBate {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsblnk.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 60;
    int frameHeight = 40;
    float duration = 0.5f;
    SDL_Rect srcRect = {13, 13, 47, 30};
    int initYSprite = 13;
    float deltaPosX = 80.0f;
    float deltaPosY = 35.0f;
};

struct HasBate {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbaim.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 1;
    int distanceBetweenFrames = 60;
    int frameWidth = 60;
    int frameHeight = 40;
    float duration = 0.5f;
    SDL_Rect srcRect = {13, 915, 47, 28};
    int initYSprite = 915;
    float deltaPosX = 80.0f;
    float deltaPosY = 35.0f;
    int initFrameAngle = 15;
    int totalFrames = 31;
    float unitAngle = 6.0f;
};

struct SavingBate {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbbak.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 60;
    int frameHeight = 40;
    float duration = 0.5f;
    SDL_Rect srcRect = {13, 13, 47, 30};
    int initYSprite = 13;
    float deltaPosX = 80.0f;
    float deltaPosY = 35.0f;
};

struct AttackAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxeswn.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 4;
    int distanceBetweenFrames = 107;
    int frameWidth = 60;
    int frameHeight = 40;
    float duration = 1.0f;
    SDL_Rect srcRect = {0, 1, 90, 65};
    int initYSprite = 1;
    float deltaPosX = 80.0f;
    float deltaPosY = 35.0f;
};

struct BatePositiveAngles {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbaim.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 64;
    int frameHeight = 60;
    float duration = 0.5f;
    SDL_Rect srcRect = {14, 975, 46, 46};
    int initYSprite = 975;
    float deltaPosX = 80.0f;
    float deltaPosY = 33.0f;
    float unitAngle = 6.0f;
};

struct BateNegativeAngles {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbaim.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 64;
    int frameHeight = 60;
    float duration = 0.5f;
    SDL_Rect srcRect = {8, 0, 51, 43};
    int initYSprite = 0;
    float deltaPosX = 75.0f;
    float deltaPosY = 75.0f;
    float unitAngle = 6.0f;
};


struct NormalAttackBate {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbbk2.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 45;
    int frameHeight = 45;
    float duration = 2.0f;
    SDL_Rect srcRect = {0, 14, 42, 29};
    int initYSprite = 14;
    float deltaPosX = 75.0f;
    float deltaPosY = 50.0f;
};

struct PositiveAnglesAttackBate {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbswn.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 54;
    int frameHeight = 55;
    float duration = 2.0f;
    SDL_Rect srcRect = {0, 960, 44, 43};
    int initYSprite = 960;
    float deltaPosX = 75.0f;
    float deltaPosY = 70.0f;
};

struct SettingBazooka {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbazlnk.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 7;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 1.0f;
    SDL_Rect srcRect = {13, 16, 33, 27};
    int initYSprite = 16;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};


struct HasBazooka {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbaz.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 1;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 50;
    float duration = 1.0f;
    SDL_Rect srcRect = {13, 972, 39, 36};
    int initYSprite = 972;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
    float unitAngle = 6.0f;
};


struct PositiveAnglesBazooka {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbaz.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 42;
    int frameHeight = 52;
    float duration = 1.0f;
    SDL_Rect srcRect = {13, 969, 38, 41};
    int initYSprite = 969;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
    float unitAngle = 6.0f;
};

struct NegativeAnglesBazooka {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbaz.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 54;
    float duration = 1.0f;
    SDL_Rect srcRect = {11, 12, 36, 40};
    int initYSprite = 12;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
    float unitAngle = 6.0f;
};


struct SavingBazooka {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbazbak.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 7;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 1.0f;
    SDL_Rect srcRect = {13, 16, 33, 27};
    int initYSprite = 16;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct NegativeAnglesAttackBate {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wbsbswn.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 54;
    int frameHeight = 55;
    float duration = 2.0f;
    SDL_Rect srcRect = {0, 14, 44, 46};
    int initYSprite = 14;
    float deltaPosX = 85.0f;
    float deltaPosY = 35.0f;
};

struct GreenGranade {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Weapons/grenade.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 22, 26};
    int initYSprite = 17;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct BazookaMissile {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Weapons/missile.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 1;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {10, 496, 40, 26};
    int initYSprite = 496;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct SettingTeleport {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wtellnk.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 40;
    float duration = 2.0f;
    SDL_Rect srcRect = {14, 15, 28, 28};
    int initYSprite = 15;
    float deltaPosX = 45.0f;
    float deltaPosY = 40.0f;
};

struct HasTeleport {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wteltlk.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 40;
    float duration = 2.0f;
    SDL_Rect srcRect = {14, 12, 28, 31};
    int initYSprite = 12;
    float deltaPosX = 48.0f;
    float deltaPosY = 40.0f;
};

struct UseTeleport {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wteldsv.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 48;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 40;
    float duration = 2.0f;
    SDL_Rect srcRect = {7, 7, 40, 40};
    int initYSprite = 7;
    float deltaPosX = 48.0f;
    float deltaPosY = 40.0f;
};
struct ProjectileExplotion {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Effects/a_explosion.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 6;
    int distanceBetweenFrames = 60;
    int frameWidth = 34;
    int frameHeight = 41;
    float duration = 5.0f;
    SDL_Rect srcRect = {0, 0, 32, 32};
    int initYSprite = 0.0f;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};



//


struct SetGreenGranade {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wgrnlnk.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 52;
    float duration = 2.0f;
    SDL_Rect srcRect = {16, 7, 38, 47};
    int initYSprite = 7;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct HasGreenGranade {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wgrnbak.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 3;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 42;
    float duration = 2.0f;
    SDL_Rect srcRect = {17, 12, 39, 35};
    int initYSprite = 7;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct SaveGreenGranade {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wgrnbak.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 10;
    int distanceBetweenFrames = 60;
    int frameWidth = 40;
    int frameHeight = 42;
    float duration = 2.0f;
    SDL_Rect srcRect = {17, 12, 39, 35};
    int initYSprite = 7;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};
