/*
서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고 31이라는 숫자를 말하는 사람이 지는 게임
1. 사용자는 본인이 입력한 숫자만큼
2. 컴퓨터는 랜덤 숫자만큼
3. 사용자, 컴퓨터 모두 1~3 사이의 개수만 가능
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> user(int num) {
    while (true) {
        cout << "개수를 입력하세요.(1~3) : ";
        int user_count;
        cin >> user_count;

        //error : 1과 3 사이의 숫자가 아닌 다른 숫자 입력
        if (user_count < 1 || user_count > 3) {
            cout << "1개에서 3개의 숫자를 입력하세요.\n" << endl;
            continue;
        }

        //error : user_count 입력했을 때 마지막 수가 31을 넘을 경우
        if (num + user_count > 31) {
            cout << "31을 넘을 수 없습니다.\n" << endl;
            continue;
        }
        // user_count 크기의 user_numbers 벡터 생성
        vector<int> user_numbers(user_count);
        for (int i = 0; i < user_count; i++) {
            user_numbers[i] = num + 1 + i; // user_count개를 user_numbers에 저장
        }

        cout << "사용자가 부른 숫자!" << endl;
        for (int user_number : user_numbers) { // user_numbers에 저장된 줄 user_number 전체 호출
            cout << user_number << endl;
        }
        cout << endl;

        return user_numbers;
    }
}

vector<int> computer(int num) {
    int com_count;

    // 31이 넘지않으며 최대 3개의 숫자를 출력할 수 있을 경우
    if (31 - num > 3) {
        com_count = rand() % 3 + 1; // 1~3의 랜덤 숫자 생성
    }
    // 31이 넘지 않게 숫자 조정
    else {
        com_count = 31 - num;
    }

    vector<int> com_numbers(com_count);
    for (int i = 0; i < com_count; i++) {
        com_numbers[i] = num + 1 + i;
    }

    cout << "컴퓨터가 부른 숫자!" << endl;
    for (int com_number : com_numbers) {
        cout << com_number << endl;
    }
    cout << endl;

    return com_numbers;
}

int main() {
    int num = 0;

    while (num < 31) {
        // user 함수를 호출하여 userNumbers에 저장
        vector<int> userNumbers = user(num);
        num = userNumbers.back(); // userNumbers의 마지막 수를 num에 저장

        if (num >= 31) {
            cout << "게임 종료! 컴퓨터의 승리입니다." << endl;
            break;
        }

        vector<int> comNumbers = computer(num);
        num = comNumbers.back();

        if (num >= 31) {
            cout << "게임 종료! 사용자의 승리입니다." << endl;
            break;
        }
    }

    return 0;
}