/*
사용자로부터 홀수 n을 입력 받아 n*n의 마방진 만들기

마방진이란?
1에서 n제곱까지의 수를 정사각형으로 배열해 가로, 세로, 대각의 합계가 모두 같도록 만든 것

규칙 (n이 홀수일 때)
1. 1은 첫 행의 가운데에 위치한다.
2. 우상단으로 갈수록 숫자가 1씩 늘어난다.
3. 우상단으로 이동하는 도중 이미 칸이 채워져 있으면 바로 아래 칸에 다음 숫자가 채워진다.
4. 첫번째 행에서 우상단으로 이동할 때는 마지막 행의 다음 열로 이동한다.
5. 마지막 열에서 우상단으로 이동할 때는 첫번째 열의 이전 행으로 이동한다.
6. 첫번째 행의 마지막 열에서는 우상단으로 이동하는 것이 아니라 바로 아래칸으로 이동한다.
*/

#include <iostream>
#include <vector>

using namespace std;

// 홀수 n에 대한 마방진 생성 함수
void generateMagicSquare(int n, vector<vector<int>>& magicSquare) {
    // n*n, 초기값 0의 2차원 벡터로 설정
    magicSquare = vector<vector<int>>(n, vector<int>(n, 0));

    // 초기 위치 설정 -> 1행 센터에 위치
    int row = 0;
    int col = n / 2;

    // 마방진에 숫자 채우기
    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num;

        // 다음 위치 계산
        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        // 다음 위치가 이미 채워져 있는 경우
        if (magicSquare[nextRow][nextCol] != 0) {
            // 아래 칸으로 이동
            row = (row + 1) % n;
        }
        else {
            // 우상단으로 이동
            row = nextRow;
            col = nextCol;
        }
    }
}

// 마방진 출력 함수
void printMagicSquare(const vector<vector<int>>& magicSquare) {
    for (const auto& row : magicSquare) {
        for (int num : row) {
            if (num < 10) { // 한 자리 수일 때 공백 추가
                cout << " ";
            }
            cout << num << " "; // 숫자 출력 후 공백 추가
        }
        cout << endl;
    }
}

int main() {
    int n;

    while (true) {
        cout << "홀수 n을 입력하세요: ";
        cin >> n;

        // 홀수인지 확인
        if (n % 2 != 0) {
            break;
        }

        // error : 짝수인 경우
        cout << "홀수를 입력해 주세요.\n" << endl;
    }

    // 마방진 생성 및 출력
    vector<vector<int>> magicSquare;
    generateMagicSquare(n, magicSquare);
    printMagicSquare(magicSquare);

    return 0;
}
