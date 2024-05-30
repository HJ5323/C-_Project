/*
1. 클래스 상속, 정적 멤버, 업캐스팅, 가상 함수를 사용하여 다음과 같이 간단한 사칙연산을 수행하는 계산기 만들기
    Y : 도출된 결과를 이용한 후속 계산
    AC : 이전 기록 초기화
    EXIT : 종료
*/

#include <iostream>

using namespace std;

// 계산기 클래스
class Calculator {
public:
    static float result; // 정적 멤버 변수: 현재 결과를 저장

    // 가상 함수: 사칙연산을 수행하는 함수
    virtual float calculate(float num1, float num2) = 0;
};

float Calculator::result = 0.0; // 정적 멤버 변수 초기화

// 덧셈 클래스
class Add : public Calculator {
public:
    float calculate(float num1, float num2) override {
        result = num1 + num2;
        return result;
    }
};

// 뺄셈 클래스
class Sub : public Calculator {
public:
    float calculate(float num1, float num2) override { // override -> calculat 함수 재정의
        result = num1 - num2;
        return result;
    }
};

// 곱셈 클래스
class Mul : public Calculator {
public:
    float calculate(float num1, float num2) override {
        result = num1 * num2;
        return result;
    }
};

// 나눗셈 클래스
class Div : public Calculator {
public:
    float calculate(float num1, float num2) override {
        result = num1 / num2;
        return result;
    }
};

int main() {
    string choice;
    float num1, num2;
    char op;
    bool continueCal = false;

    // 계산기 객체 생성
    Calculator* calculator = 0;

    do {
        if (continueCal) { // Y가 입력되었을 때
            num1 = Calculator::result;

            cout << "연산자를 입력해주세요: ";
            cin >> op;

            cout << "숫자를 입력해주세요: ";
            cin >> num2;
        }
        else { // 외의 경우
            cout << "숫자를 입력해주세요: ";
            cin >> num1;

            cout << "연산자를 입력해주세요: ";
            cin >> op;

            cout << "숫자를 입력해주세요: ";
            cin >> num2;
        }

        // 사용자 입력에 따라 객체 선택
        switch (op) {
        case '+':
            calculator = new Add();
            break;
        case '-':
            calculator = new Sub();
            break;
        case '*':
            calculator = new Mul();
            break;
        case '/':
            calculator = new Div();
            break;
        default:
            cout << "오류: 잘못된 연산자입니다." << endl;
            break;
        }

        // 계산 및 결과 출력
        if (calculator != NULL) {
            cout << "결과: " << calculator->calculate(num1, num2) << endl;
            delete calculator; // 동적 할당된 객체 삭제
        }

        while (true) {
            cout << "-------------------------------" << endl;
            cout << "연산을 계속 진행하시겠습니까? (Y: 계속, AC: 초기화, EXIT: 종료): ";
            cin >> choice;

            for (auto& c : choice) c = toupper(c); // choice의 각 문자 c를 대문자로 바꿔줌

            if (choice == "Y") {
                continueCal = true;
                break;
            }
            else if (choice == "AC") {
                Calculator::result = 0; // 계산 결과 초기화
                cout << "결과가 초기화되었습니다.\n" << endl;
                continueCal = false;
                break;
            }
            else if (choice == "EXIT") {
                cout << "종료합니다." << endl;
                return 0;
            }
            else {
                cout << "다시 입력해 주세요." << endl;
                continue;
            }
        }

    } while (true);

    return 0;
}