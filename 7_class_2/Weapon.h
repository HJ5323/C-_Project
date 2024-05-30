#pragma once
#include <iostream>

using namespace std;

class Weapon {
protected: // Gun, Sword ���� ����
    int damage;
    int remainingUses;
    string name;

public:
    Weapon(int damage, int remainingUses, const string& name);

    virtual void attack() = 0; // �����Լ�, Weapon -> �߻� Ŭ����
    int getDamage() const;
    int getRemainingUses() const;
    string getName() const;
};