/*
1. ���� �ð� 30�� ���� �÷��̾�� �����ձ� ��Ģ�� ���� �ܾ �Է�
2. ���� �ð��� ����Ǹ� ������ ���� ��Ű��, �Է��� �ܾ��� ������ ���
3. �ѹ� �Էµ� �ܾ�� �Է����� ���ϰ� �ϱ�
*/

#include <iostream>
#include <vector>
#include <ctime>
//#include <chrono>

using namespace std;

void play() {
    vector<string> userWords;
    string userWord;

    userWords.push_back("airplane"); // ù ���� �ܾ� airplane

    //auto startTime = chrono::steady_clock::now();
    //auto endTime = startTime + chrono::seconds(30);
    //while (chrono::steady_clock::now() < endTime) 

    // 30�� �ð� ����
    time_t startTime = time(NULL);
    time_t endTime = startTime + 30;

    while (time(NULL) < endTime) {

        cout << "[";
        for (int i = 0; i < userWords.size(); i++) {
            cout << userWords[i];
            if (i < userWords.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "]" << endl;

        cout << "���� �ܾ �Է��ϼ���: ";
        cin >> userWord;
        cout << endl;

        // �ߺ��� �ܾ� Ȯ��
        if (find(userWords.begin(), userWords.end(), userWord) != userWords.end()) {
            cout << "�ߺ��� �ܾ �Է��� �� �����ϴ�.\n" << endl;
            continue;
        }

        // ���� �ܾ��� �����ڿ� �Է´ܾ��� ù���� ����ġ
        if (userWords.back().back() != userWord.front()) {
            cout << "�߸��� �Է��Դϴ�.\n" << endl;
            continue;
        }

        userWords.push_back(userWord);
    }

    cout << "Ÿ�� ����!" << endl;
    cout << "�� �Է��� �ܾ��� ����: " << userWords.size() - 1 << endl; // ù �ܾ� ����
}

int main() {
    play();
    return 0;
}
