#include <iostream>
#include <vector>
using namespace std;

int main()
{
	char ar[] = "1234";

	for (char &x : ar)
	{
		cout << x << " ";
	}
}