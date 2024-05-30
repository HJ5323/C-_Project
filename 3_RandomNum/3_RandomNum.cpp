/*
1. 컴퓨터가 1~25까지의 수 중 랜덤으로 6개의 수 지정 (중복 X)
2. 사용자도 1~25까지의 수 중 원하는 숫자 6개 지정(중복 X)
3. 두 배열을 비교해서 몇 등인지 출력하기
    3-1. 한 개도 맞추지 못하면 7등, 1개만 맞추면 6등, 2개 맞추면 5등...
    3-2. 6개 모두 맞추면 1등
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// 컴퓨터 랜덤 숫자
vector<int> Computer()
{
    vector<int> comNums(25);

    for (int i = 0; i <= comNums.size() - 1; i++)
    {
        comNums[i] = i + 1; // 각 인덱스에 1부터 25까지의 값을 할당
    }

    // 숫자 섞기
    random_shuffle(comNums.begin(), comNums.end());

    // result_computer 벡터에 6개의 번호 추출
    vector<int> result_computer(comNums.begin(), comNums.begin() + 6);

    return result_computer;
}

// 사용자 숫자 선택
vector<int> User()
{
    vector<int> userNums(6); // 크기가 6인 userNums 벡터 생성
    int userNum;

    cout << "숫자는 1~25까지의 숫자만 입력할 수 있습니다." << endl;

    for (int i = 0; i <= userNums.size() - 1; i++) {
        cout << i + 1 << "번째 번호를 입력하세요. : ";
        cin >> userNum;

        //error : 1~25가 아닌 다른 숫자 입력
        if (userNum < 1 || userNum > 25) {
            cout << "잘못된 숫자입니다. 다시 입력해주세요." << endl;
            i--; // 같은 위치에 다시 입력 받음
            continue;
        }

        userNums[i] = userNum;

        // 중복된 숫자가 있는지 확인
        for (int j = 0; j < i; j++) {
            //error : 중복
            if (userNums[j] == userNum) {
                cout << "이미 입력된 숫자입니다." << endl;
                i--; // 같은 위치에 다시 입력 받음
                break;
            }
        }
    }

    // 사용자가 선택한 번호 정렬
    sort(userNums.begin(), userNums.end());

    // 사용자 선택 번호 출력
    cout << "\n사용자 입력 숫자!" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << userNums[i] << " ";
    }

    cout << "\n------------------------------" << endl;

    return userNums;
}

// 두 벡터 비교하여 당첨 등수 출력
void Compare(const vector<int>& comNums, const vector<int>& userNums)
{
    int matched = 0;
    int result;

    // 사용자가 선택한 숫자와 컴퓨터의 숫자가 몇 개가 겹치는지 확인
    /*
    find((범위 시작 반복자, 범위 끝 반복자, 찾고자 하는 값) != 끝 반복자) 함수는
        지정된 범위에서 특정값을 찾고 일치하지 않는 경우 끝 반복자 '.end()' 반환
        끝 반복자와 일치하지 않는다는 것 = 일치하는 수를 찾은 것
    */
    for (int userNum : userNums) {
        if (find(comNums.begin(), comNums.end(), userNum) != comNums.end()) {
            matched++; // 일치하는 수 찾으면 1씩 증가
        }
    }

    // 등수 출력
    switch (matched) {
    case 0: // 0개 맞췄을 때
        result = 7;
        break;
    case 1: // 1개 맞췄을 때
        result = 6;
        break;
    case 2:
        result = 5;
        break;
    case 3:
        result = 4;
        break;
    case 4:
        result = 3;
        break;
    case 5:
        result = 2;
        break;
    case 6:
        result = 1;
        break;
    default:
        cout << "잘못된 등수입니다!" << endl;
        break;
    }

    cout << endl;
    cout << "결과 : " << result << "등 입니다!" << endl;

}

int main()
{
    // 실행시 난수 초기화
    srand(time(NULL));

    // 컴퓨터가 랜덤으로 선택한 숫자 - Computer 함수를 호출하여 comNums에 저장
    vector<int> comNums = Computer();

    // 사용자가 선택한 숫자
    vector<int> userNums = User();

    sort(comNums.begin(), comNums.end());

    cout << "당첨 번호 공개!" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << comNums[i] << " ";
    }

    cout << "\n\n1~7등까지 결과가 나올 수 있습니다." << endl;

    // 컴퓨터의 숫자와 사용자의 숫자 비교하여 등수 출력
    Compare(comNums, userNums);

    return 0;
}
