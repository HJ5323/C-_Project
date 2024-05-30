#include "Character.h"
#include "Sword.h"
#include "Gun.h"
#include <iostream>
#include <vector>

using namespace std;

bool askContinue() {
    char choice;
    cout << "\n��� �����Ͻðڽ��ϱ�? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y'); // Y, y �Է� true ��ȯ
}

int main() {
    // ���Ͽ��� ĳ���� ���� �ҷ�����
    string character_file = "Characters.txt";
    vector<Character> characters = Character::loadCharacters(character_file); // Characters.txt �ҷ��� characters ���Ϳ� ����

    // ĳ���� ���� ���
    cout << "�ҷ��� ĳ���� ��: " << characters.size() << endl; 
    for (const auto& character : characters) {
        cout << "�̸�: " << character.getName() << ", ����: " << character.getLevel() << ", HP: " << character.getHp() << endl;
    }

    if (characters.size() < 3) {
        cout << "ĳ���Ͱ� ������� �ʽ��ϴ�. ������ Ȯ���ϼ���." << endl;
        return 1;
    }

    // A, B, C ĳ���� ����
    Character& A = characters[0];
    Character& B = characters[1];
    Character& C = characters[2];

    unique_ptr<Weapon> sword = make_unique<Sword>(); 
    unique_ptr<Weapon> gun = make_unique<Gun>();

    // �ݺ��ؼ� ����
    char choice;
    do {
        // ĳ���� ���� �� ����
        int attackerIdx, targetIdx, weaponIdx;
        cout << "\n������ ĳ���� ���� (0: A, 1: B, 2: C): ";
        cin >> attackerIdx;
        cout << "���ݹ޴� ĳ���� ���� (0: A, 1: B, 2: C): ";
        cin >> targetIdx;
        cout << "����� ���� ���� (0: Sword, 1: Gun): ";
        cin >> weaponIdx;

        if (attackerIdx < 0 || attackerIdx >= characters.size() || targetIdx < 0 || targetIdx >= characters.size()) {
            cout << "�߸��� ĳ���� �����Դϴ�." << endl;
            continue; 
        }

        Character& attacker = characters[attackerIdx];

        // ���� ����
        attacker.pickWeapon(move(sword));
        attacker.pickWeapon(move(gun));

        Character& target = characters[targetIdx];

        attacker.attack(target, weaponIdx);

        if (attacker.getWeapons()[weaponIdx]->getRemainingUses() == 0) {
            continue;
        }

        // ����� ĳ���� ���� ����
        Character::saveCharacters(character_file, characters);


    } while (askContinue());

    return 0;
}