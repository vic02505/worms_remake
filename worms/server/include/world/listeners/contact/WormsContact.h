#pragma once

#include "world/entities/WWorm.h"
#include <iostream>

class WormsContact  {
public:
    void BeginContact(b2Body* bodyA, b2Body* bodyB);
    void EndContact(b2Body* bodyA, b2Body* bodyB);
};