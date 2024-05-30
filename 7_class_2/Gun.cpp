#include "Gun.h"

Gun::Gun() : Weapon(10, 1, "Gun") {}

void Gun::attack() {
    if (remainingUses > 0) {
        cout << "\nÃÑ½î±â!";
        remainingUses--;
    }
    else {
        cout << "Gun »ç¿ë È½¼ö ºÎÁ·" << endl;
    }
}