#include "world/entities/WDeadWorm.h"

WDeadWorm::WDeadWorm(b2World* world, int id, b2Vec2 position, float width, float height) {
    m_Id = id;
    m_World = world;
    m_Width = width;
    m_Height = height;
    m_Position = position;
    b2BodyDef bd;
    bd.position.Set(m_Position.x, m_Position.y);
    bd.type = b2_staticBody;
    bd.userData.pointer = reinterpret_cast<uintptr_t>(this);
    b2Body * body = m_World->CreateBody(&bd);
    b2PolygonShape shape;
    b2FixtureDef myFixtureDef;
    shape.SetAsBox(m_Width, m_Height);
    myFixtureDef.shape = &shape;
    myFixtureDef.density = 1;
    body->CreateFixture(&myFixtureDef);
}

EntitiesType WDeadWorm::getEntityType() {
    return EntitiesType::ENTITY_DEAD_WORM;
}
