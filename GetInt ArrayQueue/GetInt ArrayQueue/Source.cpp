#include <iostream>
#include <string>
//#include <ctype.h>
#include "ArrayQueue.h"
using namespace std;
int getInteger(ArrayQueue<char>& aQueue);


int main()
{

	ArrayQueue<char> aQueue;
	string someString;

	cout << " Enter integers\n";
	getline(cin, someString);

	cout << "Passing information: ";

	char ch;
	int len = 0;
	while (len != someString.length())
	{
		ch = someString[len];

		aQueue.enqueue(ch);

		len++;
	}


	int integer = getInteger(aQueue);
	cout << " The integer is : " << integer;

	return 0;

}






int getInteger(ArrayQueue<char>& aQueue)
{
	char ch;
	do
	{
		ch = aQueue.peekFront();
		aQueue.dequeue();
	} while (ch == ' ');
	// Assertion: ch contains first digit  
	// Compute the integer n from digits in queue   
	int n = 0;
	bool done = false;
	do
	{
		
		n = 10 * n + (ch-48);

		done = aQueue.isEmpty();
		if (!done)
		{
			ch = aQueue.peekFront();
			aQueue.dequeue();
		}
	} while (!done && isdigit(ch));
	
	return n;
}