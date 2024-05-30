/*
1. ��ǻ�Ͱ� 1~25������ �� �� �������� 6���� �� ���� (�ߺ� X)
2. ����ڵ� 1~25������ �� �� ���ϴ� ���� 6�� ����(�ߺ� X)
3. �� �迭�� ���ؼ� �� ������ ����ϱ�
    3-1. �� ���� ������ ���ϸ� 7��, 1���� ���߸� 6��, 2�� ���߸� 5��...
    3-2. 6�� ��� ���߸� 1��
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// ��ǻ�� ���� ����
vector<int> Computer()
{
    vector<int> comNums(25);

    for (int i = 0; i <= comNums.size() - 1; i++)
    {
        comNums[i] = i + 1; // �� �ε����� 1���� 25������ ���� �Ҵ�
    }

    // ���� ����
    random_shuffle(comNums.begin(), comNums.end());

    // result_computer ���Ϳ� 6���� ��ȣ ����
    vector<int> result_computer(comNums.begin(), comNums.begin() + 6);

    return result_computer;
}

//vector<int> Computer() 
//{
//    vector<int> comNums;
//
//    // 1���� 25������ ���ڸ� ���Ϳ� ����
//    for (int i = 1; i <= 25; i++) 
//    {
//        comNums.push_back(i);
//    }
//
//    // ���� ����
//    random_shuffle(comNums.begin(), comNums.end());
//
//    // result_computer ���Ϳ� 6���� ��ȣ ����
//    vector<int> result_computer(comNums.begin(), comNums.begin() + 6);
//
//    return result_computer;
//}

// ����� ���� ����
vector<int> User()
{
    vector<int> userNums(6); // ũ�Ⱑ 6�� userNums ���� ����
    int userNum;

    cout << "���ڴ� 1~25������ ���ڸ� �Է��� �� �ֽ��ϴ�." << endl;

    for (int i = 0; i <= userNums.size() - 1; i++) {
        cout << i + 1 << "��° ��ȣ�� �Է��ϼ���. : ";
        cin >> userNum;

        //error : 1~25�� �ƴ� �ٸ� ���� �Է�
        if (userNum < 1 || userNum > 25) {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
            i--; // ���� ��ġ�� �ٽ� �Է� ����
            continue;
        }

        userNums[i] = userNum;

        // �ߺ��� ���ڰ� �ִ��� Ȯ��
        for (int j = 0; j < i; j++) {
            //error : �ߺ�
            if (userNums[j] == userNum) {
                cout << "�̹� �Էµ� �����Դϴ�." << endl;
                i--; // ���� ��ġ�� �ٽ� �Է� ����
                break;
            }
        }
    }

    // ����ڰ� ������ ��ȣ ����
    sort(userNums.begin(), userNums.end());

    // ����� ���� ��ȣ ���
    cout << "\n����� �Է� ����!" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << userNums[i] << " ";
    }

    cout << "\n------------------------------" << endl;

    return userNums;
}

// �� ���� ���Ͽ� ��÷ ��� ���
void Compare(const vector<int>& comNums, const vector<int>& userNums)
{
    int matched = 0;
    int result;

    // ����ڰ� ������ ���ڿ� ��ǻ���� ���ڰ� �� ���� ��ġ���� Ȯ��
    /*
    find((���� ���� �ݺ���, ���� �� �ݺ���, ã���� �ϴ� ��) != �� �ݺ���) �Լ���
        ������ �������� Ư������ ã�� ��ġ���� �ʴ� ��� �� �ݺ��� '.end()' ��ȯ
        �� �ݺ��ڿ� ��ġ���� �ʴ´ٴ� �� = ��ġ�ϴ� ���� ã�� ��
    */
    for (int userNum : userNums) {
        if (find(comNums.begin(), comNums.end(), userNum) != comNums.end()) {
            matched++; // ��ġ�ϴ� �� ã���� 1�� ����
        }
    }

    // ��� ���
    switch (matched) {
    case 0: // 0�� ������ ��
        result = 7;
        break;
    case 1: // 1�� ������ ��
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
        cout << "�߸��� ����Դϴ�!" << endl;
        break;
    }

    cout << endl;
    cout << "��� : " << result << "�� �Դϴ�!" << endl;

}


int main()
{
    // ����� ���� �ʱ�ȭ
    srand(time(NULL));

    // ��ǻ�Ͱ� �������� ������ ���� - Computer �Լ��� ȣ���Ͽ� comNums�� ����
    vector<int> comNums = Computer();

    // ����ڰ� ������ ����
    vector<int> userNums = User();

    sort(comNums.begin(), comNums.end());

    cout << "��÷ ��ȣ ����!" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << comNums[i] << " ";
    }

    cout << "\n\n1~7����� ����� ���� �� �ֽ��ϴ�." << endl;

    // ��ǻ���� ���ڿ� ������� ���� ���Ͽ� ��� ���
    Compare(comNums, userNums);

    return 0;
}