#include "world/entities/WBeam.h"

WBeam::WBeam(b2World* world, const Grd& beam) {
    this->type = EntitiesType::ENTITY_BEAM;
    this->m_GrdType = beam.grdType;
    b2BodyDef beamBodyDef;
    beamBodyDef.type = b2_staticBody;
    beamBodyDef.position.Set(beam.x, beam.y);
//    beamBodyDef.angle = 0;
    beamBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);

    m_BeamBody = world->CreateBody(&beamBodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(beam.width / 2, beam.height / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1;
    fixtureDef.friction = 0.3f;
    m_BeamBody->CreateFixture(&fixtureDef);
}

EntitiesType WBeam::getEntityType() {
    return this->type;
}

b2Body *WBeam::getBody() const {
    return m_BeamBody;
}

float WBeam::getAngle() const {
    return m_BeamBody->GetAngle();
}

b2Vec2 WBeam::getPosition() const {
    return m_BeamBody->GetPosition();
}

uint16_t WBeam::getBeamCategory() const {
    return m_BeamCategory;
}
