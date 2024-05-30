#pragma once

#include "Weapon.h"

class Sword : public Weapon {
public:
    Sword();
    void attack() override;
};