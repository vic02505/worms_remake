#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "WEntity.h"
#include <vector>

class WWater : public WEntity {
private:
    float x = 0.0f;
    float y = 0.0f;
    float width = 10.0f;
    float height = 1.0f;
    uint16 m_WaterCategory = 0x0004;
    EntitiesType m_EntityType;
public:
    WWater(b2World* world, const std::vector<uint16_t>& categories);
    EntitiesType getEntityType() override;

    ~WWater() override = default;
};