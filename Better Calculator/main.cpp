#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operand: ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    if(op == '+'){
        cout << num1 + num2;
    }
    if(op == '-'){
        cout << num1 - num2;
    }
    if(op == '*'){
        cout << num1 * num2;
    }
    if(op == '/'){
        cout << num1 / num2;
    }
    else {
        cout << "Invalid operator or number.";
    }
    return 0;
}
