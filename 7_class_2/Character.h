/*
1. ĳ����, ����, Į, �� Ŭ������ ������ش�.
2. ĳ���� Ŭ����
    - �ʵ� : 'hp', 'level', '�����'
    - �޼ҵ� : ���� �ݱ�, �����ϱ� (�����ϱ� �޼ҵ忡���� ������ �ִ� ����鸸 ����ؼ� ������ �� ������, ���ݴ��� ĳ������ hp�� �ش��ϴ� ������ ���ݷ¸�ŭ �����Ѵ�.)
3. ���� Ŭ����
    - �ʵ� : ���ݷ�, ���� ���� Ƚ��
    - �޼ҵ� : �����ϱ�
4. �� & Į Ŭ���� (���� Ŭ������ ��� �޴� Ŭ����)
    - Į : ���ݷ� = 5, ���ݰ���Ƚ�� = 3, �����ϱ� = "���" ���
    - �� : ���ݷ� = 10, ���ݰ���Ƚ�� = 1, �����ϱ� = "�ѽ��" ���
5. ���� �и��ϱ�
*/

#pragma once

#include <vector>
#include <memory> // ����Ʈ ������
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
    // ������
    Character(string name, int level, int hp);

    // ���� �ݱ� �޼ҵ�
    void pickWeapon(unique_ptr<Weapon> weapon);

    // �����ϱ� �޼ҵ�
    void attack(Character& target, int weaponIndex);

    int getHp() const;
    void setHp(int hp);

    string getName() const;

    int getLevel() const;

    const vector<unique_ptr<Weapon>>& getWeapons() const;

    static vector<Character> loadCharacters(const string& character_file);
    static void saveCharacters(const string& character_file, const vector<Character>& characters);

};
