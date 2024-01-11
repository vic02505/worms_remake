#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "resources/GrdEnum.h"

struct Grd {
    Grd(int grdType, float posX, float posY);
    Grd(int grdType, float posX, float posY, float w, float h);
    GrdEnum grdType;
    float x;
    float y;
    float width;
    float height;
};

class ParseMapFromFile {
public:
    static std::vector<Grd> parse(const std::string& mapName);
};