#include "world/listeners/contact/BazookaContact.h"

void BazookaContact::BeginContact(b2Body* bodyA, b2Body* bodyB) {

    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    //WWorm* worm;
    WProyectile* proyectile;

    if (entityA == nullptr || entityB == nullptr) {
        return;
    }

    if ((entityA->getEntityType() == EntitiesType::ENTITY_PROYECTILE && entityB->getEntityType() == EntitiesType::ENTITY_WORM) ||
        (entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_PROYECTILE) ||
        (entityA->getEntityType() == EntitiesType::ENTITY_PROYECTILE && entityB->getEntityType() == EntitiesType::ENTITY_BEAM) ||
        (entityA->getEntityType() == EntitiesType::ENTITY_BEAM && entityB->getEntityType() == EntitiesType::ENTITY_PROYECTILE)){


        std::cout << "[PROYECTILE COLLIDE]" << std::endl;
        if (entityA->getEntityType() == EntitiesType::ENTITY_PROYECTILE) {
            proyectile = reinterpret_cast<WProyectile*>(bodyA->GetUserData().pointer);
        } else if(entityB->getEntityType() == EntitiesType::ENTITY_PROYECTILE){
            proyectile = reinterpret_cast<WProyectile*>(bodyB->GetUserData().pointer);
        }

        proyectile->SetCollide();



        std::cout << "COLIISIONO" << std::endl;
    }

    //std::cout <<"No hubo colision" << std::endl;

}

void BazookaContact::EndContact(b2Body* bodyA, b2Body* bodyB) {
    //std::cout << "[PROYECTILE END COLLIDE]" << std::endl;



}