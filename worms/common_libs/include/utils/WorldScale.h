#pragma once

class WorldScale {
public:
    static float worldToPixelX(float initWorldValue, float width);
    static float worldToPixelY(float initWorldValue, float height);
    /*Estos 2 metodos pixelToWorldX y pixelToWorldY el unico proposito que tienen es para el Editor
 * Para que este cuando obtenga el SDL_Rect pueda usar estos 2 metodos para escribir en el Archivo de Mapas.*/
    static float pixelToWorldX(float initPixelValue, float width);
    static float pixelToWorldY(float initPixelValue, float height);
    static float toPixel(float initWorldValue);
public:
    static const float worldScaleMeasure;
    static const float heightWindow;
    static const float worldToPixelWidthWorm;
    static const float worldToPixelHeightWorm;
};
