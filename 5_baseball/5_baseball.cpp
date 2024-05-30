/*
1. ����ڴ� 1���� 9���� �� 3���� ���ڸ� �̾� ��ǻ�Ͱ� �������� ���� ���� 3���� �� (�ߺ�X)
2. ������ �ڸ��� ���� ��� ������ strike
3. �ڸ��� �ٸ����� 3���� ���� �� ���ԵǾ� ������ ball
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// ��ǻ�� ���� ����
//vector<int> Computer()
//{
//    vector<int> comNums(9);
//
//    for (int i = 0; i <= comNums.size() - 1; i++)
//    {
//        comNums[i] = i + 1; // �� �ε����� 1���� 9������ ���� �Ҵ�
//    }
//
//    // ���� ����
//    random_shuffle(comNums.begin(), comNums.end());
//
//    // result_computer ���Ϳ� 3���� ��ȣ ����
//    vector<int> result_computer(comNums.begin(), comNums.begin() + 3);
//
//    return result_computer;
//}

void Computer(vector<int>& comNums)
{
    comNums.resize(9);

    for (int i = 0; i <= comNums.size() - 1; i++)
    {
        comNums[i] = i + 1; // �� �ε����� 1���� 9������ ���� �Ҵ�
    }

    // ���� ����
    random_shuffle(comNums.begin(), comNums.end());

    //result_computer ���Ϳ� 3���� ��ȣ ����
    vector<int> result_computer(comNums.begin(), comNums.begin() + 3);

    // result_computer ���Ϳ� 3���� ��ȣ ����
    comNums.resize(3);
}

// ����� ���� ����
//vector<int> User()
//{
//    vector<int> userNums; // ũ�Ⱑ 3�� userNums ���� ����
//    int userNum;
//
//    cout << "1~9 ������ ���� 3���� �Է� �Ͻÿ�. (�̿��� ���� : ����)" << endl;
//
//    while (userNums.size() < 3) {
//        cin >> userNum;
//
//        //error : 1~25�� �ƴ� �ٸ� ���� �Է�
//        if (userNum < 1 || userNum > 9) {
//            cout << "\n������ �����մϴ�." << endl;
//            exit(0);
//        }
//        else if (find(userNums.begin(), userNums.end(), userNum) != userNums.end()) {
//            cout << "�ߺ��� ��ȣ�� �Է��� �� �����ϴ�." << endl;
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
    userNums.clear(); // userNums ���� �ʱ�ȭ
    int userNum;

    cout << "1~9 ������ ���� 3���� �Է� �Ͻÿ�. (�̿��� ���� : ����)" << endl;

    while (userNums.size() < 3) {
        cin >> userNum;

        //error : 1~25�� �ƴ� �ٸ� ���� �Է�
        if (userNum < 1 || userNum > 9) {
            cout << "\n������ �����մϴ�." << endl;
            exit(0);
        }
        else if (find(userNums.begin(), userNums.end(), userNum) != userNums.end()) {
            cout << "�ߺ��� ��ȣ�� �Է��� �� �����ϴ�." << endl;
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

    // ����� ���� �ʱ�ȭ
    srand(time(NULL));

    // ��ǻ�Ͱ� �������� ������ ���� - Computer �Լ��� ȣ���Ͽ� comNums�� ����
    //vector<int> comNums = Computer();
    vector<int> comNums;
    Computer(comNums);

    int strikes = 0;
    int balls = 0;
    int attempts = 0;

    do {
        // ����ڰ� ������ ����
        //vector<int> userNums = User();
        vector<int> userNums;
        User(userNums);
        attempts++;

        StrikeAndBall(comNums, userNums, strikes, balls);

        if (strikes == 3) {
            cout << "\n����!\n" << attempts << "�� ���� ������ϴ�." << endl;
            break;
        }

        cout << "Strike : " << strikes << "       Ball : " << balls << endl;
        cout << endl;

    } while (strikes < 3);

    return 0;
}