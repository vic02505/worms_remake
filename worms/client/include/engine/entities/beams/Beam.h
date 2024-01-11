#pragma once

#include <SDL_render.h>
#include "utils/WorldScale.h"
#include "engine/graphics/Texture.h"
#include "engine/entities/TexturePaths.h"
#include <filesystem>
#include "ParseMapFromFile.h"

class Beam {
 private:
    SDL_Renderer* m_Renderer;
    Texture* m_BeamTexture{};
    SDL_Rect m_DestBeamRect{};
    float m_BeamWidth{};
    float m_BeamHeight{};
    GrdEnum m_BeamType;

 public:
    Beam(SDL_Renderer* renderer, const Grd& grd);

    void init();
    void release();
    void render();
    SDL_Rect& getBeamRect();
};