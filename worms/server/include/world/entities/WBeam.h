#pragma once

#include <vector>
#include "../../../../Box2D/include/box2d/box2d.h"
#include "EntitiesType.h"
#include "WEntity.h"
#include "ParseMapFromFile.h"

class WBeam : public WEntity {
 private:
    uint16_t m_BeamCategory = 0x0002;
    b2Body* m_BeamBody{};
    GrdEnum m_GrdType;
 public:
    WBeam(b2World* world, const Grd& beam);

    WBeam();

    [[nodiscard]] b2Body* getBody() const;
    [[nodiscard]] b2Vec2 getPosition() const;
    [[nodiscard]] float getAngle() const;
    [[nodiscard]] uint16_t getBeamCategory() const;
    [[nodiscard]] EntitiesType getEntityType() override;

    ~WBeam() override = default;
};