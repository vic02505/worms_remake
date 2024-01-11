#include "world/listeners/contact/WaterContact.h"

void WaterContact::BeginContact(b2Body* bodyA, b2Body* bodyB) {

    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    WWorm* worm;
    WWater* water;
    if (entityA == nullptr || entityB == nullptr) {
        return;
    }

    if ((entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_WATER)
        || (entityA->getEntityType() == EntitiesType::ENTITY_WATER && entityB->getEntityType() == EntitiesType::ENTITY_WORM)) {
        std::cout << "[WATER COLLIDE]" << std::endl;
        if (entityA->getEntityType() == EntitiesType::ENTITY_WORM) {
            worm = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
            water = reinterpret_cast<WWater*>(bodyB->GetUserData().pointer);
        } else {
            worm = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);
            water = reinterpret_cast<WWater*>(bodyA->GetUserData().pointer);
        }
        worm->setIsDead();
        std::cout << water->getEntityType() << std::endl;
    }
}

void WaterContact::EndContact(b2Body* bodyA, b2Body* bodyB) {
    //std::cout << "[END WATER COLLIDE]" << std::endl;
}
