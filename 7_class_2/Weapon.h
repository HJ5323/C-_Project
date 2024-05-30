#pragma once
#include <iostream>

using namespace std;

class Weapon {
protected: // Gun, Sword 접근 가능
    int damage;
    int remainingUses;
    string name;

public:
    Weapon(int damage, int remainingUses, const string& name);

    virtual void attack() = 0; // 가상함수, Weapon -> 추상 클래스
    int getDamage() const;
    int getRemainingUses() const;
    string getName() const;
};