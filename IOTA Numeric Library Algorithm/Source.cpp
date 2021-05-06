//Increments each 1 on each index after original number.

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	vector<int> vecNums(10);

	iota(begin(vecNums), end(vecNums), 1);		//First parameter is start of container, second parameter is end of container and third parameter is starting number for incrementation.

	for (auto x : vecNums)
		cout << x << endl;

	return 0;
}