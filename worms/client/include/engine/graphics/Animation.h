#pragma once

#include <SDL_render.h>
#include <string>
#include "Texture.h"


class Animation {
    Texture *m_Texture;
    int m_Frames;
    int m_DistanceBetweenFrames;
    int m_FrameWidth;
    int m_FrameHeight;
    float m_Duration;
    double m_CurrentTime;
    SDL_Rect m_SourceRect;
    int m_InitYSprite;
    SDL_Rect m_DestRect;
    float m_DeltaPosX;
    float m_DeltaPosY;

public:
    Animation(std::string path, SDL_Renderer *renderer, BlendMode blendMode,
              int frames, int distanceBetweenFrames, int frameWidth, int frameHeight, float duration,
              SDL_Rect srcRect, int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY);

    void init();
    void update(double elapsedSeconds, int specificFrame = -1);
    void render(bool isFlip) const;


    void setPositions(float x, float y);
    void setDestDimensions(int width, int height);
    void setDestRect(SDL_Rect destRect);
    SDL_Rect& getDestRect();
    float getDeltaPosX() const;
    float getDeltaPosY() const;
    int getFrameWidth() const;
    int getFrameHeight() const;

    ~Animation();
};
