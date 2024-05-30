#include "Sword.h"

Sword::Sword() : Weapon(5, 3, "Sword") {}

void Sword::attack() {
    if (remainingUses > 0) {
        cout << "\nÂî¸£±â!" << endl;
        remainingUses--;
    }
    else {
        cout << "Sword »ç¿ë È½¼ö ºÎÁ·" << endl;
    }
}
