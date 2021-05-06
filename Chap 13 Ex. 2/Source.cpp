#include <iostream>
#include <string>
using namespace std;

#include "ArrayQueue.h"
#include "ArrayStack.h"

template<class ItemType>
bool isL(ArrayQueue<ItemType>& queue, ArrayStack<ItemType>& stack, string str)
{
	int i = 0;

	if (str.length() == 1 && str[0] == '$')
		return true;
	else if (str.length() == 0)
		return false;
	else
	{
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] == '$')
				break;
			else
				queue.enqueue(str[i]);
		}
		i++;
		for (i = i; i < str.length(); i++)
			stack.push(str[i]);
	}

	while(!stack.isEmpty() || !queue.isEmpty())
	{
		if (stack.peek() != queue.peekFront())
			return false;
		stack.pop();
		queue.dequeue();
	}
	return true;
}

int main()
{
	ArrayStack<char> stack;
	ArrayQueue<char> queue;
	string L;

	cout << "Enter the L string: " << endl;
	cin >> L;

	bool checkL = isL(queue, stack, L);
	
	if (checkL)
		cout << "The string " << L << " is of the language L." << endl;
	else
		cout << "The string " << L << " is not of the language L." << endl;


	return 0;
}

/*
Enter the L string:
abc$cba
The string abc$cba is of the language L.

Enter the L string:
adhsflkja$ajkdlf;kl
The string adhsflkja$ajkdlf;kl is not of the language L.
*/