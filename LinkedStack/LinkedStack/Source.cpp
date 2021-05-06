#include <iostream>
using namespace std;

#include "LinkedStack.h"

int main()
{
	LinkedStack<int> stack;

	stack.push(30);
	stack.push(10);
	stack.push(-20);
	stack.push(-30);
	stack.push(50);
	stack.push(90);
	stack.push(95);
	stack.push(-25);
	stack.removeNegative();
	stack.display();

	return 0;
}

/*
Top: 95
90
50
10
30
Press any key to continue . . .
*/