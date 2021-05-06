#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "LinkedStack.h"

int precedence(char ch)
{
	if (ch == '*' || ch == '/')
		return 1;
	else
		return 0;
}

int main()
{
	LinkedStack<char> operandStack;
	LinkedStack<char> optrStack;
	string exp;
	char optr, operand1, operand2, result = 'z';

	cout << "Enter arithmetric expression: " << endl;
	getline(cin, exp);
	cin.ignore();

	cout << "|" << "Operator" << setw(5) << "   |   " << setw(5) << "Operand1" << setw(5)  << "   |   " << setw(5) << "Operand2" << setw(5) << "   |   " << setw(5) << "Result" << setw(4) << "  |" << endl;
	int i = 0, size = exp.length();
	for (int i = 0; i < size; i++)
	{
		if (exp[i] >= 'a' && exp[i] <= 'm')
		{
			operandStack.push(exp[i]);
		}
		else if (exp[i] == ' ')
		{
			//Nothing
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if (optrStack.isEmpty() || precedence(exp[i]) > precedence(optrStack.peek()))
				optrStack.push(exp[i]);
			else if (precedence(exp[i]) <= precedence(optrStack.peek()))
			{
				do{
				optr = optrStack.peek();
				optrStack.pop();
				operand2 = operandStack.peek();
				operandStack.pop();
				operand1 = operandStack.peek();
				operandStack.pop();
				cout << "|" << optr << setw(14) << "   |   " << setw(5) << operand1 << setw(10) << "   |   " << setw(5) << operand2 << setw(10) << "   |   " << setw(5) << result << setw(5) << "  |" << endl;
				operandStack.push(result);
				result--;
				} while (!optrStack.isEmpty() && !(precedence(exp[i]) > precedence(optrStack.peek())));
				optrStack.push(exp[i]);
			}
		}
		
	}

		while (!operandStack.isEmpty() && !optrStack.isEmpty())
		{
			optr = optrStack.peek();
			optrStack.pop();
			operand2 = operandStack.peek();
			operandStack.pop();
			operand1 = operandStack.peek();
			operandStack.pop();
			cout << "|" << optr << setw(14) << "   |   " << setw(5) << operand1 << setw(10) << "   |   " << setw(5) << operand2 << setw(10) << "   |   " << setw(5) << result << setw(5) << "  |" << endl;
			operandStack.push(result);
			result--;
		}

	return 0;
}

/*
DISPLAY:

Enter arithmetric expression:
a + b * c - d

|Operator   |   Operand1   |   Operand2   |   Result   |
|*          |       b      |       c      |       z    |
|+          |       a      |       z      |       y    |
|-          |       y      |       d      |       x    |

Enter arithmetric expression:
a * b - c / d

|Operator   |   Operand1   |   Operand2   |   Result   |
|*          |       a      |       b      |       z    |
|/          |       c      |       d      |       y    |
|-          |       z      |       y      |       x    |

*/