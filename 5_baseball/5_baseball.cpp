/*
1. 사용자는 1부터 9까지 중 3개의 숫자를 뽑아 컴퓨터가 랜덤으로 뽑은 숫자 3개와 비교 (중복X)
2. 숫자의 자리와 값이 모두 같으면 strike
3. 자리는 다르지만 3개의 숫자 중 포함되어 있으면 ball
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// 컴퓨터 랜덤 숫자
//vector<int> Computer()
//{
//    vector<int> comNums(9);
//
//    for (int i = 0; i <= comNums.size() - 1; i++)
//    {
//        comNums[i] = i + 1; // 각 인덱스에 1부터 9까지의 값을 할당
//    }
//
//    // 숫자 섞기
//    random_shuffle(comNums.begin(), comNums.end());
//
//    // result_computer 벡터에 3개의 번호 추출
//    vector<int> result_computer(comNums.begin(), comNums.begin() + 3);
//
//    return result_computer;
//}

void Computer(vector<int>& comNums)
{
    comNums.resize(9);

    for (int i = 0; i <= comNums.size() - 1; i++)
    {
        comNums[i] = i + 1; // 각 인덱스에 1부터 9까지의 값을 할당
    }

    // 숫자 섞기
    random_shuffle(comNums.begin(), comNums.end());

    //result_computer 벡터에 3개의 번호 추출
    vector<int> result_computer(comNums.begin(), comNums.begin() + 3);

    // result_computer 벡터에 3개의 번호 추출
    comNums.resize(3);
}

// 사용자 숫자 선택
//vector<int> User()
//{
//    vector<int> userNums; // 크기가 3인 userNums 벡터 생성
//    int userNum;
//
//    cout << "1~9 사이의 숫자 3개를 입력 하시오. (이외의 숫자 : 종료)" << endl;
//
//    while (userNums.size() < 3) {
//        cin >> userNum;
//
//        //error : 1~25가 아닌 다른 숫자 입력
//        if (userNum < 1 || userNum > 9) {
//            cout << "\n게임을 종료합니다." << endl;
//            exit(0);
//        }
//        else if (find(userNums.begin(), userNums.end(), userNum) != userNums.end()) {
//            cout << "중복된 번호를 입력할 수 없습니다." << endl;
//            continue;
//        }
//        else {
//            userNums.push_back(userNum);
//        }
//    }
//
//    return userNums;
//}

void User(vector<int>& userNums)
{
    userNums.clear(); // userNums 벡터 초기화
    int userNum;

    cout << "1~9 사이의 숫자 3개를 입력 하시오. (이외의 숫자 : 종료)" << endl;

    while (userNums.size() < 3) {
        cin >> userNum;

        //error : 1~25가 아닌 다른 숫자 입력
        if (userNum < 1 || userNum > 9) {
            cout << "\n게임을 종료합니다." << endl;
            exit(0);
        }
        else if (find(userNums.begin(), userNums.end(), userNum) != userNums.end()) {
            cout << "중복된 번호를 입력할 수 없습니다." << endl;
            continue;
        }
        else {
            userNums.push_back(userNum);
        }
    }
}

void StrikeAndBall(const vector<int>& comNums, const vector<int>& userNums, int& strikes, int& balls) {

    strikes = 0;
    balls = 0;

    for (int i = 0; i < 3; i++) {
        if (userNums[i] == comNums[i]) {
            strikes++;
        }
        else if (find(comNums.begin(), comNums.end(), userNums[i]) != comNums.end()) {
            balls++;
        }
    }
}

int main() {

    // 실행시 난수 초기화
    srand(time(NULL));

    // 컴퓨터가 랜덤으로 선택한 숫자 - Computer 함수를 호출하여 comNums에 저장
    //vector<int> comNums = Computer();
    vector<int> comNums;
    Computer(comNums);

    int strikes = 0;
    int balls = 0;
    int attempts = 0;

    do {
        // 사용자가 선택한 숫자
        //vector<int> userNums = User();
        vector<int> userNums;
        User(userNums);
        attempts++;

        StrikeAndBall(comNums, userNums, strikes, balls);

        if (strikes == 3) {
            cout << "\n정답!\n" << attempts << "번 만에 맞췄습니다." << endl;
            break;
        }

        cout << "Strike : " << strikes << "       Ball : " << balls << endl;
        cout << endl;

    } while (strikes < 3);

    return 0;
}