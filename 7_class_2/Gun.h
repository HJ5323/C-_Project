#pragma once

#include "Weapon.h"

class Gun : public Weapon {
public:
    Gun();
    void attack() override;
};
