/*
����ڷκ��� Ȧ�� n�� �Է� �޾� n*n�� ������ �����

�������̶�?
1���� n���������� ���� ���簢������ �迭�� ����, ����, �밢�� �հ谡 ��� ������ ���� ��

��Ģ (n�� Ȧ���� ��)
1. 1�� ù ���� ����� ��ġ�Ѵ�.
2. �������� ������ ���ڰ� 1�� �þ��.
3. �������� �̵��ϴ� ���� �̹� ĭ�� ä���� ������ �ٷ� �Ʒ� ĭ�� ���� ���ڰ� ä������.
4. ù��° �࿡�� �������� �̵��� ���� ������ ���� ���� ���� �̵��Ѵ�.
5. ������ ������ �������� �̵��� ���� ù��° ���� ���� ������ �̵��Ѵ�.
6. ù��° ���� ������ �������� �������� �̵��ϴ� ���� �ƴ϶� �ٷ� �Ʒ�ĭ���� �̵��Ѵ�.
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// Ȧ�� n�� ���� ������ ���� �Լ�
//vector<vector<int>> generateMagicSquare(int n) {
//    vector<vector<int>> magicSquare(n, vector<int>(n, 0)); // n*n, �ʱⰪ 0
//
//    // �ʱ� ��ġ ���� -> 1�� ���Ϳ� ��ġ
//    int row = 0;
//    int col = n / 2;
//
//    // �������� ���� ä���
//    for (int num = 1; num <= n * n; num++) {
//        magicSquare[row][col] = num;
//
//        // ���� ��ġ ���
//        int nextRow = (row - 1 + n) % n;
//        int nextCol = (col + 1) % n;
//
//        // ���� ��ġ�� �̹� ä���� �ִ� ���
//        if (magicSquare[nextRow][nextCol] != 0) {
//            // �Ʒ� ĭ���� �̵�
//            row = (row + 1) % n;
//        }
//        else {
//            // �������� �̵�
//            row = nextRow;
//            col = nextCol;
//        }
//    }
//
//    return magicSquare;
//}
//
//// ������ ��� �Լ�
//void printMagicSquare(const vector<vector<int>>& magicSquare) {
//    for (const auto& row : magicSquare) {
//        for (int num : row) {
//            if (num < 10) { // �� �ڸ� ���� �� ���� �߰�
//                cout << " ";
//            }
//            cout << num << " "; // ���� ��� �� ���� �߰�
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int n;
//
//    while (true) {
//        cout << "Ȧ�� n�� �Է��ϼ���: ";
//        cin >> n;
//
//        // Ȧ������ Ȯ��
//        if (n % 2 != 0) {
//            break;
//        }
//
//        // error : ¦���� ���
//        cout << "Ȧ���� �Է��� �ּ���.\n" << endl;
//    }
//
//    // ������ ���� �� ���
//    vector<vector<int>> magicSquare = generateMagicSquare(n);
//    printMagicSquare(magicSquare);
//
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

// Ȧ�� n�� ���� ������ ���� �Լ�
void generateMagicSquare(int n, vector<vector<int>>& magicSquare) {
    // n*n, �ʱⰪ 0�� 2���� ���ͷ� ����
    magicSquare = vector<vector<int>>(n, vector<int>(n, 0));

    // �ʱ� ��ġ ���� -> 1�� ���Ϳ� ��ġ
    int row = 0;
    int col = n / 2;

    // �������� ���� ä���
    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num;

        // ���� ��ġ ���
        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        // ���� ��ġ�� �̹� ä���� �ִ� ���
        if (magicSquare[nextRow][nextCol] != 0) {
            // �Ʒ� ĭ���� �̵�
            row = (row + 1) % n;
        }
        else {
            // �������� �̵�
            row = nextRow;
            col = nextCol;
        }
    }
}

// ������ ��� �Լ�
void printMagicSquare(const vector<vector<int>>& magicSquare) {
    for (const auto& row : magicSquare) {
        for (int num : row) {
            if (num < 10) { // �� �ڸ� ���� �� ���� �߰�
                cout << " ";
            }
            cout << num << " "; // ���� ��� �� ���� �߰�
        }
        cout << endl;
    }
}

int main() {
    int n;

    while (true) {
        cout << "Ȧ�� n�� �Է��ϼ���: ";
        cin >> n;

        // Ȧ������ Ȯ��
        if (n % 2 != 0) {
            break;
        }

        // error : ¦���� ���
        cout << "Ȧ���� �Է��� �ּ���.\n" << endl;
    }

    // ������ ���� �� ���
    vector<vector<int>> magicSquare;
    generateMagicSquare(n, magicSquare);
    printMagicSquare(magicSquare);

    return 0;
}