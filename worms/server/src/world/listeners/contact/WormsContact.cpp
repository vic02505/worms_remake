#include "world/listeners/contact/WormsContact.h"

void WormsContact::BeginContact(b2Body* bodyA, b2Body* bodyB) {
    if (bodyA->GetType() == b2_staticBody || bodyB->GetType() == b2_staticBody) {
        return;
    }
    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    WWorm* wormA = nullptr;
    WWorm* wormB = nullptr;
    if (entityA == nullptr || entityB == nullptr) {
        return;
    }
    if (entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_WORM) {
        wormA = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
        wormB = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);
    }
    if (wormA != nullptr && wormB != nullptr) {
        std::cout << "[BEGIN WORM COLLIDE]" << std::endl;
        wormA->setIsInContactWithAnotherWorm(true);
        wormB->setIsInContactWithAnotherWorm(true);
        bodyA->SetLinearVelocity(b2Vec2_zero);
        bodyB->SetLinearVelocity(b2Vec2_zero);
        float xA = wormA->getPosition().x;
        float xB = wormB->getPosition().x;

        if (xA < xB) {
            wormA->setOtherDirection(Direction::RIGHT);
            wormB->setOtherDirection(Direction::LEFT);
        } else {
            wormA->setOtherDirection(Direction::LEFT);
            wormB->setOtherDirection(Direction::RIGHT);
        }
    }
}

void WormsContact::EndContact(b2Body* bodyA, b2Body* bodyB) {
    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    WWorm* wormA = nullptr;
    WWorm* wormB = nullptr;

    if (entityA == nullptr || entityB == nullptr) {
        return;
    }

    if (entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_WORM) {
        wormA = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
        wormB = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);
    }

    if (wormA != nullptr && wormB != nullptr) {
        std::cout << "END WORM COLLIDE" << std::endl;
        wormA->setIsInContactWithAnotherWorm(false);
        wormB->setIsInContactWithAnotherWorm(false);
    }
}
