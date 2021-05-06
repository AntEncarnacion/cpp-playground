#include <iostream>
using namespace std;

int product(int* anArray, int first, int last)
{
	if (first >= last)
		return anArray[last];
	else
		return anArray[first] * product(anArray, first + 1, last);
}

int main() {
	int anArray[] = { 4,8,10,12,16,32 };
	cout << product(anArray, 2, 4) << endl;

	return 0;
}