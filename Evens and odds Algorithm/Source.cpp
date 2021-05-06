#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vecNums = { 1, 7, 6, 1, 4, 8, 9, 7 };

	for (auto x : vecNums)
	{
		if (0 == (x % 2))
			cout << x << " is even" << endl;
		else
			cout << x << " is odd" << endl;
	}
	return 0;
}