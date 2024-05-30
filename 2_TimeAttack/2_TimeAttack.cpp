/*
1. 제한 시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
2. 제한 시간이 종료되면 게임을 종료 시키고, 입력한 단어의 개수를 출력
3. 한번 입력된 단어는 입력하지 못하게 하기
*/

#include <iostream>
#include <vector>
#include <ctime>
//#include <chrono>

using namespace std;

void play() {
    vector<string> userWords;
    string userWord;

    userWords.push_back("airplane"); // 첫 시작 단어 airplane

    //auto startTime = chrono::steady_clock::now();
    //auto endTime = startTime + chrono::seconds(30);
    //while (chrono::steady_clock::now() < endTime) 

    // 30초 시간 제한
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

        cout << "다음 단어를 입력하세요: ";
        cin >> userWord;
        cout << endl;

        // 중복된 단어 확인
        if (find(userWords.begin(), userWords.end(), userWord) != userWords.end()) {
            cout << "중복된 단어를 입력할 수 없습니다.\n" << endl;
            continue;
        }

        // 이전 단어의 끝글자와 입력단어의 첫글자 불일치
        if (userWords.back().back() != userWord.front()) {
            cout << "잘못된 입력입니다.\n" << endl;
            continue;
        }

        userWords.push_back(userWord);
    }

    cout << "타임 오버!" << endl;
    cout << "총 입력한 단어의 개수: " << userWords.size() - 1 << endl; // 첫 단어 제외
}

int main() {
    play();
    return 0;
}
