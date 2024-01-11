#pragma once

#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_pixels.h>
#include <assert.h>
#include <utility>

struct BlendMode {
    bool isBlendMode;
    Uint8 r, g, b;
};

class Texture {
 private:
    std::string m_Path;
    SDL_Renderer* m_Renderer;
    SDL_Rect m_SourceRect;
    SDL_Texture* m_Texture;
    BlendMode m_BlendMode;

 public:
    Texture(std::string path, SDL_Renderer* renderer, BlendMode blendMod);

    void init();
    void release();
    void setSourceRect(const SDL_Rect *rect);
    void render(const SDL_Rect *destRect, bool isFlip) const;

    ~Texture();
};
