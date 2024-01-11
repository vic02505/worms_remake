#pragma once

#include "../../../../../Box2D/include/box2d/box2d.h"
#include "world/entities/WWorm.h"
#include "world/entities/WWater.h"
#include <iostream>

class WaterContact {
 public:
    void BeginContact(b2Body* bodyA, b2Body* bodyB);
    void EndContact(b2Body* bodyA, b2Body* bodyB);
};