#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double num1, num2;
    char opt;

    // UI_First
    cout << "Enter your expression: ";
    cin >> num1 >> opt >> num2;

     // //UI_Second
    // cout<<"Enter first number: ";
    // cin>>num1;
    // cout<<"Enter second number: ";
    // cin>>num2;
    // cout<<"Enter the operation you want to perform: ";
    // cin>>opt;

    switch (opt) {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                cout << num1 / num2;
            } else {
                cout << "Error: Division by zero";
            }
            break;
        case '%':
            // Check if both numbers are integers
            if (fmod(num1, 1.0) == 0 && fmod(num2, 1.0) == 0) {
                cout << int(num1) % int(num2);
            } else {
                cout << "Error: Modulus can only be applied to integers";
            }
            break;
        default:
            cout << "Error: Invalid Operator";
            break;
    }

    return 0;
}
