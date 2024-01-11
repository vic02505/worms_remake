#include "world/listeners/ContactListener.h"

void ContactListener::BeginContact(b2Contact *contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    wormsContact.BeginContact(bodyA, bodyB);
    waterContact.BeginContact(bodyA, bodyB);
    bazookaContact.BeginContact(bodyA, bodyB);
}

void ContactListener::EndContact(b2Contact *contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    wormsContact.EndContact(bodyA, bodyB);
    waterContact.EndContact(bodyA, bodyB);
    bazookaContact.EndContact(bodyA, bodyB);
}
