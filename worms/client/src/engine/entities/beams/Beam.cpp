#include "engine/entities/beams/Beam.h"

Beam::Beam(SDL_Renderer *renderer, const Grd& grd) {
    m_Renderer = renderer;
    m_BeamWidth = WorldScale::toPixel(grd.width);
    m_BeamHeight = WorldScale::toPixel(grd.height);
    m_BeamType = grd.grdType;

    m_DestBeamRect = {static_cast<int>(WorldScale::worldToPixelX(grd.x, m_BeamWidth)),
                      static_cast<int>(WorldScale::worldToPixelY(grd.y, m_BeamHeight)),
                      static_cast<int>(m_BeamWidth), static_cast<int>(m_BeamHeight)};
}

void Beam::init() {
    BlendMode blendMode = {false, 128, 128, 192};
    switch (m_BeamType) {
        case GrdEnum::GRD_LARGE_HORIZONTAL:
            m_BeamTexture = new Texture(std::filesystem::current_path().concat(Map_Grdl_Large_Horizontal.c_str()).c_str(),
                                        m_Renderer, blendMode);
            break;
        case GrdEnum::GRD_LARGE_VERTICAL:
            m_BeamTexture = new Texture(std::filesystem::current_path().concat(Map_Grdl_Large_Vertical.c_str()).c_str(),
                                        m_Renderer, blendMode);
            break;
        case GrdEnum::GRD_SMALL_HORIZONTAL:
            m_BeamTexture = new Texture(std::filesystem::current_path().concat(Map_Grds_Small_Horizontal.c_str()).c_str(),
                                        m_Renderer, blendMode);
            break;
        case GrdEnum::GRD_SMALL_VERTICAL:
            m_BeamTexture = new Texture(std::filesystem::current_path().concat(Map_Grds_Small_Vertical.c_str()).c_str(),
                                        m_Renderer, blendMode);
            break;
        default:
            break;
    }

    m_BeamTexture->init();
}

void Beam::render() {
    m_BeamTexture->render(&m_DestBeamRect, false);
}

void Beam::release() {
    m_BeamTexture->release();
    delete m_BeamTexture;
}

SDL_Rect& Beam::getBeamRect(){
    return m_DestBeamRect;
}

