#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2;
    char choice;

    do {
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch(op) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Cannot divide by zero." << endl;
                break;
            default:
                cout << "Invalid operator!" << endl;
        }
        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye! see you again." << endl;
    return 0;
}