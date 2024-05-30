/*
1. 캐릭터, 무기, 칼, 총 클래스를 만들어준다.
2. 캐릭터 클래스
    - 필드 : 'hp', 'level', '무기들'
    - 메소드 : 무기 줍기, 공격하기 (공격하기 메소드에서는 가지고 있는 무기들만 사용해서 공격할 수 있으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼 감소한다.)
3. 무기 클래스
    - 필드 : 공격력, 공격 가능 횟수
    - 메소드 : 공격하기
4. 총 & 칼 클래스 (무기 클래스를 상속 받는 클래스)
    - 칼 : 공격력 = 5, 공격가능횟수 = 3, 공격하기 = "찌르기" 출력
    - 총 : 공격력 = 10, 공격가능횟수 = 1, 공격하기 = "총쏘기" 출력
5. 파일 분리하기
*/

#pragma once

#include <vector>
#include <memory> // 스마트 포인터
#include <string>
#include "Weapon.h"

using namespace std;

class Character {
private:
    string name;
    int level;
    int hp;
    vector<unique_ptr<Weapon>> weapons;

public:
    // 생성자
    Character(string name, int level, int hp);

    // 무기 줍기 메소드
    void pickWeapon(unique_ptr<Weapon> weapon);

    // 공격하기 메소드
    void attack(Character& target, int weaponIndex);

    int getHp() const;
    void setHp(int hp);

    string getName() const;

    int getLevel() const;

    const vector<unique_ptr<Weapon>>& getWeapons() const;

    static vector<Character> loadCharacters(const string& character_file);
    static void saveCharacters(const string& character_file, const vector<Character>& characters);

};
