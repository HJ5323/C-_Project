/*
���� �ּ� 1������ �ִ� 3���� ���ӵ� ���ڸ� ���ϰ� 31�̶�� ���ڸ� ���ϴ� ����� ���� ����
1. ����ڴ� ������ �Է��� ���ڸ�ŭ
2. ��ǻ�ʹ� ���� ���ڸ�ŭ
3. �����, ��ǻ�� ��� 1~3 ������ ������ ����
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> user(int num) {
    while (true) {
        cout << "������ �Է��ϼ���.(1~3) : ";
        int user_count;
        cin >> user_count;

        //error : 1�� 3 ������ ���ڰ� �ƴ� �ٸ� ���� �Է�
        if (user_count < 1 || user_count > 3) {
            cout << "1������ 3���� ���ڸ� �Է��ϼ���.\n" << endl;
            continue;
        }

        //error : user_count �Է����� �� ������ ���� 31�� ���� ���
        if (num + user_count > 31) {
            cout << "31�� ���� �� �����ϴ�.\n" << endl;
            continue;
        }
        // user_count ũ���� user_numbers ���� ����
        vector<int> user_numbers(user_count);
        for (int i = 0; i < user_count; i++) {
            user_numbers[i] = num + 1 + i; // user_count���� user_numbers�� ����
        }

        cout << "����ڰ� �θ� ����!" << endl;
        for (int user_number : user_numbers) { // user_numbers�� ����� �� user_number ��ü ȣ��
            cout << user_number << endl;
        }
        cout << endl;

        return user_numbers;
    }
}

vector<int> computer(int num) {
    int com_count;

    // 31�� ���������� �ִ� 3���� ���ڸ� ����� �� ���� ���
    if (31 - num > 3) {
        com_count = rand() % 3 + 1; // 1~3�� ���� ���� ����
    }
    // 31�� ���� �ʰ� ���� ����
    else {
        com_count = 31 - num;
    }

    vector<int> com_numbers(com_count);
    for (int i = 0; i < com_count; i++) {
        com_numbers[i] = num + 1 + i;
    }

    cout << "��ǻ�Ͱ� �θ� ����!" << endl;
    for (int com_number : com_numbers) {
        cout << com_number << endl;
    }
    cout << endl;

    return com_numbers;
}

int main() {
    int num = 0;

    while (num < 31) {
        // user �Լ��� ȣ���Ͽ� userNumbers�� ����
        vector<int> userNumbers = user(num);
        num = userNumbers.back(); // userNumbers�� ������ ���� num�� ����

        if (num >= 31) {
            cout << "���� ����! ��ǻ���� �¸��Դϴ�." << endl;
            break;
        }

        vector<int> comNumbers = computer(num);
        num = comNumbers.back();

        if (num >= 31) {
            cout << "���� ����! ������� �¸��Դϴ�." << endl;
            break;
        }
    }

    return 0;
}