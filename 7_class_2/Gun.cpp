#include "Gun.h"

Gun::Gun() : Weapon(10, 1, "Gun") {}

void Gun::attack() {
    if (remainingUses > 0) {
        cout << "\n�ѽ��!";
        remainingUses--;
    }
    else {
        cout << "Gun ��� Ƚ�� ����" << endl;
    }
}