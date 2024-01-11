#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "messages/server/GameUpdate.h"
#include "world/entities/weapons/WeaponFactory.h"
#include "world/entities/weapons/impl/Axe.h"
#include "world/entities/weapons/impl/Bate.h"
#include "messages/user_actions/ActionType.h"
#include "EntitiesType.h"
#include "WEntity.h"
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

class WDeadWorm : public WEntity {
private:
    int m_Id;
    b2World* m_World{};
    b2Body* m_Body{};
    float m_Width{};
    float m_Height{};
    b2Vec2 m_Position{};
public:
    WDeadWorm(b2World* world, int id, b2Vec2 position, float width, float height);
    EntitiesType getEntityType() override;
};