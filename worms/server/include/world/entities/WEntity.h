#pragma once

#include "EntitiesType.h"

class WEntity {
 protected:
    EntitiesType type = EntitiesType::NO_ENTITY;
 public:
    virtual EntitiesType getEntityType() = 0;
    virtual ~WEntity() = default;
};