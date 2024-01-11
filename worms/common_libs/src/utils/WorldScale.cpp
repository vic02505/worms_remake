#include "../include/utils/WorldScale.h"

const float WorldScale::worldScaleMeasure = 25.6f;
const float WorldScale::heightWindow = 512.0f;
const float WorldScale::worldToPixelWidthWorm = 40.96f;
const float WorldScale::worldToPixelHeightWorm = 25.6f;

float WorldScale::pixelToWorldX(float initPixelValue, float width) {
    float scaledValue = initPixelValue / worldScaleMeasure;
    return scaledValue + (width / 2);
}

float WorldScale::pixelToWorldY(float initPixelValue, float height) {
    float scaledValue = initPixelValue / worldScaleMeasure;
    float heightWorld = heightWindow / worldScaleMeasure;
    return (heightWorld - scaledValue) + (height / 2);
}

float WorldScale::worldToPixelX(float initWorldValue, float width) {
    float scaledValue = worldScaleMeasure * initWorldValue;
    return scaledValue - (width / 2);
}

float WorldScale::worldToPixelY(float initWorldValue, float height) {
    float scaledValue = worldScaleMeasure * initWorldValue;
    float m = heightWindow - scaledValue;
    float n = height / 2;
    return m - n;
}

float WorldScale::toPixel(float initWorldValue) {
    return worldScaleMeasure * initWorldValue;
}
