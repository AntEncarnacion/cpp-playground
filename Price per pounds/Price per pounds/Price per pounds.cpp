// Price per pounds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	float weight, price;

	cout << "Please type the weight of your package: ";
	cin >> weight;

	if (weight < 2.0) 
	{
		price = weight * 1.50;

	}
	else if (weight <= 6.0 && weight >= 2.0) 
	{
		price = weight * 3.00;

	}
	else if (weight <= 10.0 && weight > 6.0)
	{
		price = weight * 4.00;

	}
	else if(weight > 10.0)
	{
		price = weight * 4.75;
	}

	cout << "The cost is " << price << endl;

	return 0;
}

