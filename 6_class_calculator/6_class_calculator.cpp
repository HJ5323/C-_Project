/*
1. Ŭ���� ���, ���� ���, ��ĳ����, ���� �Լ��� ����Ͽ� ������ ���� ������ ��Ģ������ �����ϴ� ���� �����
    Y : ����� ����� �̿��� �ļ� ���
    AC : ���� ��� �ʱ�ȭ
    EXIT : ����
*/

#include <iostream>

using namespace std;

// ���� Ŭ����
class Calculator {
public:
    static float result; // ���� ��� ����: ���� ����� ����

    // ���� �Լ�: ��Ģ������ �����ϴ� �Լ�
    virtual float calculate(float num1, float num2) = 0;
};

float Calculator::result = 0.0; // ���� ��� ���� �ʱ�ȭ

// ���� Ŭ����
class Add : public Calculator {
public:
    float calculate(float num1, float num2) override {
        result = num1 + num2;
        return result;
    }
};

// ���� Ŭ����
class Sub : public Calculator {
public:
    float calculate(float num1, float num2) override { // override -> calculat �Լ� ������
        result = num1 - num2;
        return result;
    }
};

// ���� Ŭ����
class Mul : public Calculator {
public:
    float calculate(float num1, float num2) override {
        result = num1 * num2;
        return result;
    }
};

// ������ Ŭ����
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

    // ���� ��ü ����
    Calculator* calculator = 0;

    do {
        if (continueCal) { // Y�� �ԷµǾ��� ��
            num1 = Calculator::result;

            cout << "�����ڸ� �Է����ּ���: ";
            cin >> op;

            cout << "���ڸ� �Է����ּ���: ";
            cin >> num2;
        }
        else { // ���� ���
            cout << "���ڸ� �Է����ּ���: ";
            cin >> num1;

            cout << "�����ڸ� �Է����ּ���: ";
            cin >> op;

            cout << "���ڸ� �Է����ּ���: ";
            cin >> num2;
        }

        // ����� �Է¿� ���� ��ü ����
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
            cout << "����: �߸��� �������Դϴ�." << endl;
            break;
        }

        // ��� �� ��� ���
        if (calculator != NULL) {
            cout << "���: " << calculator->calculate(num1, num2) << endl;
            delete calculator; // ���� �Ҵ�� ��ü ����
        }

        while (true) {
            cout << "-------------------------------" << endl;
            cout << "������ ��� �����Ͻðڽ��ϱ�? (Y: ���, AC: �ʱ�ȭ, EXIT: ����): ";
            cin >> choice;

            for (auto& c : choice) c = toupper(c); // choice�� �� ���� c�� �빮�ڷ� �ٲ���

            if (choice == "Y") {
                continueCal = true;
                break;
            }
            else if (choice == "AC") {
                Calculator::result = 0; // ��� ��� �ʱ�ȭ
                cout << "����� �ʱ�ȭ�Ǿ����ϴ�.\n" << endl;
                continueCal = false;
                break;
            }
            else if (choice == "EXIT") {
                cout << "�����մϴ�." << endl;
                return 0;
            }
            else {
                cout << "�ٽ� �Է��� �ּ���." << endl;
                continue;
            }
        }

    } while (true);

    return 0;
}