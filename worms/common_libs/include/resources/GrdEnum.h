#pragma once

#include <string>

enum GrdEnum : uint8_t {
    GRD_LARGE_VERTICAL = 0x00,
    GRD_LARGE_HORIZONTAL = 0x01,
    GRD_LARGE_DIAGONAL_0 = 0x02,
    GRD_LARGE_DIAGONAL_1 = 0x03,
    GRD_LARGE_DIAGONAL_2 = 0x04,
    GRD_SMALL_VERTICAL = 0x05,
    GRD_SMALL_HORIZONTAL = 0x06,
    GRD_SMALL_DIAGONAL_0 = 0x07,
    GRD_SMALL_DIAGONAL_1 = 0x08,
    GRD_SMALL_DIAGONAL_2 = 0x09
};

namespace GrdWidthEnum {
    const float GRD_HORIZONTAL_WIDTH_LARGE = 10;
    const float GRD_WIDTH_SMALL = 5;
    const float GRD_VERTICAL_WIDTH_LARGE = 1;
};

namespace GrdHeightEnum {
    const float GRD_HORIZONTAL_HEIGHT_LARGE = 1.0f;
    const float GRD_HEIGHT_SMALL = 1.0f;
    const float GRD_VERTICAL_HEIGHT_LARGE = 10.0f;
}
