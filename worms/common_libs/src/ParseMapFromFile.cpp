#include "../include/ParseMapFromFile.h"

std::vector<Grd> ParseMapFromFile::parse(const std::string& mapName) {
    std::ifstream inputFile(std::filesystem::current_path().concat("/maps/").concat(mapName + ".txt"));
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open file" << std::endl;
    }

    int numGrds;
    std::vector<Grd> grds;
    inputFile >> numGrds;
    for (int i = 0; i < numGrds; i++) {
        float x, y;
        int type;
        inputFile >> type >> x >> y;
        grds.emplace_back(type, x, y);
    }
    inputFile.close();
    return grds;
}

Grd::Grd(int grdType, float posX, float posY) {
    this->grdType = static_cast<GrdEnum>(grdType);
    this->x = posX;
    this->y = posY;
    switch (grdType) {
        case GRD_SMALL_HORIZONTAL:
            this->width = GrdWidthEnum::GRD_WIDTH_SMALL;
            this->height = GrdHeightEnum::GRD_HEIGHT_SMALL;
            break;
        case GRD_LARGE_HORIZONTAL:
            this->width = GrdWidthEnum::GRD_HORIZONTAL_WIDTH_LARGE;
            this->height = GrdHeightEnum::GRD_HORIZONTAL_HEIGHT_LARGE;
            break;
        case GRD_LARGE_VERTICAL:
            this->width = GrdWidthEnum::GRD_VERTICAL_WIDTH_LARGE;
            this->height = GrdHeightEnum::GRD_VERTICAL_HEIGHT_LARGE;
            break;
        default:
            this->width = 10.0f;
            this->height = 1.0f;
            break;
    }
}

Grd::Grd(int grdType, float posX, float posY, float w, float h) {
    this->grdType = static_cast<GrdEnum>(grdType);
    this->x = posX;
    this->y = posY;
    this->width = w;
    this->height = h;
}
