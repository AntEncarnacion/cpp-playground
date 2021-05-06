#include <iostream>
using namespace std;
#include "Rectangle_Class.h"

int main()
{
	Rectangle box;

	double rectLength;
	double rectWidth;

	cout << "This program will calculate the area of a\n";
	cout << "rectangle. What is the width? ";

	cin >> rectWidth;
	cout << "What is the length? ";
	cin >> rectLength;

	box.setWidth(rectWidth);
	box.setLength(rectLength);
	box.display();

	system("pause");
	return 0;
}

/*This program will calculate the area of a
rectangle. What is the width? 10
What is the length? 5
Here is the rectangle's data:
Width: 10
Length: 5
Area: 50
Perimeter:30
Press any key to continue . . .*/