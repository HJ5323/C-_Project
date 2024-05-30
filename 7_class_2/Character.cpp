#include "Character.h"
#include <fstream>
#include <sstream>

Character::Character(string name, int level, int hp) : name(name), level(level), hp(hp) {}

void Character::pickWeapon(unique_ptr<Weapon> weapon) { 
    weapons.push_back(move(weapon)); 
}

void Character::attack(Character& target, int weaponIndex) {
    if (weaponIndex < 0 || weaponIndex >= weapons.size()) {
        cout << "���⸦ ã�� �� �����ϴ�." << endl;
        return;
    }

    if (weapons[weaponIndex]->getRemainingUses() > 0) {
        weapons[weaponIndex]->attack();
        target.setHp(target.getHp() - weapons[weaponIndex]->getDamage());
        cout << " " << getName() << "�� " << target.getName() << "�� �����Ͽ����ϴ�." << endl;
        cout << "���� �� " << target.getName() << "�� HP: " << target.getHp() << endl;
    }
    else {
        weapons[weaponIndex]->attack();
    }
}

int Character::getHp() const { // hp ���� ������
    return hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

string Character::getName() const {
    return name;
}

int Character::getLevel() const {
    return level;
}

const vector<unique_ptr<Weapon>>& Character::getWeapons() const { 
    return weapons;
}

vector<Character> Character::loadCharacters(const string& character_file) {
    vector<Character> characters;
    ifstream file(character_file);
    if (!file.is_open()) {
        cout << "������ �� �� �����ϴ�." << endl;
        return characters;
    }

    string line;
    while (getline(file, line)) { // ���ڿ� �Ľ�
        istringstream iss(line);
        string name;
        int level, hp;
        if (iss >> name >> level >> hp) {
            characters.emplace_back(name, level, hp);
        }
        else {
            cout << "�߸��� ������ ������: " << line << endl;
        }
    }

    file.close();
    return characters;
}

void Character::saveCharacters(const string& character_file, const vector<Character>& characters) {
    ofstream file(character_file);
    if (!file.is_open()) {
        cout << "������ �� �� �����ϴ�." << endl;
        return;
    }

    for (const auto& character : characters) {
        file << character.name << " " << character.level << " " << character.hp << endl;
    }

    file.close();
}

