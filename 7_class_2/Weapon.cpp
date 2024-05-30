#include "Weapon.h"

Weapon::Weapon(int damage, int remainingUses, const string& name)
    : damage(damage), remainingUses(remainingUses), name(name) {}

int Weapon::getDamage() const {
    return damage;
}

int Weapon::getRemainingUses() const {
    return remainingUses;
}

string Weapon::getName() const {
    return name;
}