#include "world/entities/WWater.h"

WWater::WWater(b2World* world, const std::vector<uint16_t>& categories) {
    b2BodyDef waterBodyDef;
    waterBodyDef.type = b2_staticBody;
    waterBodyDef.position.Set(10.0f, 1.0f);
    waterBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    b2Body* water = world->CreateBody(&waterBodyDef);

    b2PolygonShape waterShape;
    waterShape.SetAsBox(10, 1);

    b2FixtureDef waterFixtureDef;
    waterFixtureDef.shape = &waterShape;
    waterFixtureDef.density = 1;
    water->CreateFixture(&waterFixtureDef);

    b2Filter filter;
    filter.categoryBits = m_WaterCategory;
    for (unsigned short category : categories) {
        filter.maskBits |= category;
    }

    water->GetFixtureList()->SetFilterData(filter);
    m_EntityType = EntitiesType::ENTITY_WATER;
}

EntitiesType WWater::getEntityType() {
    return m_EntityType;
}

