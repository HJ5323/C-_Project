#include "Sword.h"

Sword::Sword() : Weapon(5, 3, "Sword") {}

void Sword::attack() {
    if (remainingUses > 0) {
        cout << "\n���!" << endl;
        remainingUses--;
    }
    else {
        cout << "Sword ��� Ƚ�� ����" << endl;
    }
}
