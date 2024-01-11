#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "world/listeners/contact/WormsContact.h"
#include "world/listeners/contact/WaterContact.h"
#include "world/listeners/contact/BazookaContact.h"

class ContactListener : public b2ContactListener {
private:
    WormsContact wormsContact;
    WaterContact waterContact;
    BazookaContact bazookaContact;
 public:
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;
};