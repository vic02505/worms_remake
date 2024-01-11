#include "../include/camara.h"


Camara::Camara(SDL_Renderer *renderer) : _renderer(renderer) {
    float zoom = 1.8f;
    camara_rect = {0,0, 512, 512};
    SDL_RenderSetScale(_renderer, zoom, 1);
}


void Camara::updateCamera(){
    
    camara_rect.w = WorldScale::toPixel(worm->m_Widht);
    camara_rect.h = WorldScale::toPixel(worm->m_Height);
    camara_rect.x = WorldScale::worldToPixelX(worm->m_WormXPosition, worm->m_Widht) - (camara_rect.w/2); 
    camara_rect.y = WorldScale::worldToPixelY(worm->m_WormYPosition, worm->m_Height) - (camara_rect.h/2);

    //int pos_x = WorldScale::worldToPixelX(worm->m_WormXPosition, worm->m_Widht);
    //int pos_y =  WorldScale::worldToPixelY(worm->m_WormYPosition, worm->m_Height);


    if (camara_rect.x < 0) {camara_rect.x = 0;}
    if (camara_rect.y < 0) {camara_rect.y = 0;}
    if (camara_rect.x > camara_rect.w) {camara_rect.x = camara_rect.w;}
    if (camara_rect.y > camara_rect.h) {camara_rect.y = camara_rect.h;}

    //SDL_Rect& worm_rect = worm->getWormRect();

    //worm_rect.x = pos_x - camara_rect.x;
    //worm_rect.y = pos_y - camara_rect.y;

    //SDL_RenderFillRect(_renderer, &camara_rect);
    
    
}

void Camara::setWorm(Worm *worm) {
    this->worm = worm;
}




