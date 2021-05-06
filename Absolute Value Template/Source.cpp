#include <iostream>
#include<iomanip>
using namespace std;

template<class T>
T absolute(T num)
{
	if (num < 0)
		return num * -1;
	else
		return num;
}

int main() {
	int int1;
	float float1;
	char char1;
	string string1;


	cout << setprecision(5);
	cout << "Enter an integers: ";
	cin >> int1;
	cout << "Absolute value: " << absolute(int1) << endl;

	cout << setprecision(5);
	cout << "Enter a floats: ";
	cin >> float1;
	cout << "Absolute value: " << absolute(float1) << endl;


	return 0;
}