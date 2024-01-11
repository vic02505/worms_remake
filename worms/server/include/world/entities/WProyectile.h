#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "WEntity.h"
#include "world/entities/WWorm.h"
#include <vector>

class WProyectile : public WEntity {
private:

    EntitiesType m_EntityType;
    b2Body* m_Body;
    b2World* m_World;

    float m_Radius;
    uint16_t m_BeamCategory = 0x0002;
    uint16_t m_WormCategory = 0x0003;
    uint16_t m_BazookaCategory = 0x0005;

    bool explotion{false};


public:
    WProyectile(b2World* world, WWorm* attacker);
    EntitiesType getEntityType() override;

    b2Body* getBody();

    float getPositionX();

    float getPositionY();

    float getRadius();

    void deleteBody();

    void SetCollide();

    bool GetCollide();

    ~WProyectile() override = default;
};

