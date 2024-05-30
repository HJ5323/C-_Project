#include "Character.h"
#include "Sword.h"
#include "Gun.h"
#include <iostream>
#include <vector>

using namespace std;

bool askContinue() {
    char choice;
    cout << "\n계속 공격하시겠습니까? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y'); // Y, y 입력 true 반환
}

int main() {
    // 파일에서 캐릭터 정보 불러오기
    string character_file = "Characters.txt";
    vector<Character> characters = Character::loadCharacters(character_file); // Characters.txt 불러와 characters 벡터에 저장

    // 캐릭터 정보 출력
    cout << "불러온 캐릭터 수: " << characters.size() << endl; 
    for (const auto& character : characters) {
        cout << "이름: " << character.getName() << ", 레벨: " << character.getLevel() << ", HP: " << character.getHp() << endl;
    }

    if (characters.size() < 3) {
        cout << "캐릭터가 충분하지 않습니다. 파일을 확인하세요." << endl;
        return 1;
    }

    // A, B, C 캐릭터 설정
    Character& A = characters[0];
    Character& B = characters[1];
    Character& C = characters[2];

    unique_ptr<Weapon> sword = make_unique<Sword>(); 
    unique_ptr<Weapon> gun = make_unique<Gun>();

    // 반복해서 공격
    char choice;
    do {
        // 캐릭터 선택 및 공격
        int attackerIdx, targetIdx, weaponIdx;
        cout << "\n공격자 캐릭터 선택 (0: A, 1: B, 2: C): ";
        cin >> attackerIdx;
        cout << "공격받는 캐릭터 선택 (0: A, 1: B, 2: C): ";
        cin >> targetIdx;
        cout << "사용할 무기 선택 (0: Sword, 1: Gun): ";
        cin >> weaponIdx;

        if (attackerIdx < 0 || attackerIdx >= characters.size() || targetIdx < 0 || targetIdx >= characters.size()) {
            cout << "잘못된 캐릭터 선택입니다." << endl;
            continue; 
        }

        Character& attacker = characters[attackerIdx];

        // 무기 소지
        attacker.pickWeapon(move(sword));
        attacker.pickWeapon(move(gun));

        Character& target = characters[targetIdx];

        attacker.attack(target, weaponIdx);

        if (attacker.getWeapons()[weaponIdx]->getRemainingUses() == 0) {
            continue;
        }

        // 변경된 캐릭터 정보 저장
        Character::saveCharacters(character_file, characters);


    } while (askContinue());

    return 0;
}