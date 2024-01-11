#include "world/entities/WProyectile.h"

WProyectile::WProyectile(b2World* world, WWorm* attacker) : m_World(world) {

    b2BodyDef projectileBodyDef;
    projectileBodyDef.type = b2_dynamicBody;
    projectileBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);

    if (attacker->getDirection() == Direction::LEFT) {
        projectileBodyDef.position.Set(attacker->getPosition().x - 1, attacker->getPosition().y + 0.5);
    } else {
        projectileBodyDef.position.Set(attacker->getPosition().x + 1, attacker->getPosition().y + 0.5);
    }

    m_Body = m_World->CreateBody(&projectileBodyDef);


    b2CircleShape projectileShape;
    projectileShape.m_radius = 0.13f;

    b2FixtureDef projectileFixtureDef;
    projectileFixtureDef.shape = &projectileShape;
    projectileFixtureDef.density = 1.0f;
    projectileFixtureDef.friction = 0.2f;
    projectileFixtureDef.restitution = 0.0f;
    m_Body->CreateFixture(&projectileFixtureDef);

    b2Filter filter;
    filter.categoryBits = m_BazookaCategory;

    std::vector<uint16_t> categories = {m_WormCategory, m_BeamCategory};

    for(unsigned short category : categories) {
        filter.maskBits |= category;
    }

    m_Body->GetFixtureList()->SetFilterData(filter);

    m_EntityType = EntitiesType::ENTITY_PROYECTILE;
    m_Radius = 2.0f;
}

b2Body* WProyectile::getBody() {
    return m_Body;
}

float WProyectile::getPositionX() {
    return m_Body->GetPosition().x;
}

float WProyectile::getPositionY() {
    return m_Body->GetPosition().y;
}

float WProyectile::getRadius() {
    return m_Radius;
}

EntitiesType WProyectile::getEntityType() {
    return m_EntityType;
}

void WProyectile::deleteBody() {
    //m_World->Step(0.0f, 0, 0);
    m_World->DestroyBody(m_Body);
}

void WProyectile::SetCollide() {
    explotion = true;
}

bool WProyectile::GetCollide() {
    return explotion;
}