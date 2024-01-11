#include "engine/graphics/Animation.h"

Animation::Animation(std::string path, SDL_Renderer *renderer, BlendMode blendMode, int frames,
                     int distanceBetweenFrames, int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                     int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY) :
                     m_Texture(new Texture(std::move(path), renderer, blendMode)),
                     m_Frames(frames), m_DistanceBetweenFrames(distanceBetweenFrames), m_FrameWidth(frameWidth),
                     m_FrameHeight(frameHeight), m_Duration(duration), m_CurrentTime(0.0f), m_SourceRect(srcRect),
                     m_InitYSprite(initYSprite), m_DestRect(destRect), m_DeltaPosX(deltaPosX), m_DeltaPosY(deltaPosY) {}

void Animation::init() {
    m_Texture->init();
}

void Animation::update(double elapsedSeconds, int specificFrame) {
    if (specificFrame != -1) {
        m_SourceRect.y = (specificFrame * m_DistanceBetweenFrames) + m_InitYSprite;
        m_Texture->setSourceRect(&m_SourceRect);
        return;
    }
    m_CurrentTime += elapsedSeconds;

    if (m_CurrentTime > m_Duration) {
        m_CurrentTime -= m_Duration;
    }

    auto frameIndex = int(m_CurrentTime / m_Duration * m_Frames);

    m_SourceRect.y = (frameIndex * m_DistanceBetweenFrames) + m_InitYSprite;
    m_Texture->setSourceRect(&m_SourceRect);
}

void Animation::render(bool isFlip) const {
    m_Texture->render(&m_DestRect, isFlip);
}

void Animation::setPositions(float x, float y) {
    m_DestRect.x = x;
    m_DestRect.y = y;
}

void Animation::setDestDimensions(int width, int height) {
    m_DestRect.w = width;
    m_DestRect.h = height;
}

void Animation::setDestRect(SDL_Rect destRect) {
    //CORRECT POSITIONS
    if (destRect.x < 0) destRect.x = 0;
    if (destRect.y < 0) destRect.y = 0;
    if (destRect.x + destRect.w > 512) destRect.x = 512 - destRect.w;
    if (destRect.y + destRect.h > 512) destRect.y = 512 - destRect.h;
    m_DestRect = destRect;
}

SDL_Rect &Animation::getDestRect() {
    return m_DestRect;
}

Animation::~Animation() {
    delete m_Texture;
}

float Animation::getDeltaPosX() const {
    return m_DeltaPosX;
}

float Animation::getDeltaPosY() const {
    return m_DeltaPosY;
}

int Animation::getFrameWidth() const {
    return m_FrameWidth;
}

int Animation::getFrameHeight() const {
    return m_FrameHeight;
}

