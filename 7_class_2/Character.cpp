#include "Character.h"
#include <fstream>
#include <sstream>

Character::Character(string name, int level, int hp) : name(name), level(level), hp(hp) {}

void Character::pickWeapon(unique_ptr<Weapon> weapon) { 
    weapons.push_back(move(weapon)); 
}

void Character::attack(Character& target, int weaponIndex) {
    if (weaponIndex < 0 || weaponIndex >= weapons.size()) {
        cout << "무기를 찾을 수 없습니다." << endl;
        return;
    }

    if (weapons[weaponIndex]->getRemainingUses() > 0) {
        weapons[weaponIndex]->attack();
        target.setHp(target.getHp() - weapons[weaponIndex]->getDamage());
        cout << " " << getName() << "가 " << target.getName() << "를 공격하였습니다." << endl;
        cout << "공격 후 " << target.getName() << "의 HP: " << target.getHp() << endl;
    }
    else {
        weapons[weaponIndex]->attack();
    }
}

int Character::getHp() const { // hp 값만 가져옴
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
        cout << "파일을 열 수 없습니다." << endl;
        return characters;
    }

    string line;
    while (getline(file, line)) { // 문자열 파싱
        istringstream iss(line);
        string name;
        int level, hp;
        if (iss >> name >> level >> hp) {
            characters.emplace_back(name, level, hp);
        }
        else {
            cout << "잘못된 형식의 데이터: " << line << endl;
        }
    }

    file.close();
    return characters;
}

void Character::saveCharacters(const string& character_file, const vector<Character>& characters) {
    ofstream file(character_file);
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }

    for (const auto& character : characters) {
        file << character.name << " " << character.level << " " << character.hp << endl;
    }

    file.close();
}

