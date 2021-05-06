// Hotel Room Rental.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int num_small, num_large, tax;
	const int price_small = 25;
	const int price_large = 35;
	
	cout << "Hello welcome to Anthony's room rental\n\n";
	cout << "How many small rooms would you like: ";
	cin >> num_small;
	cout << "\nHow many large rooms would you like: ";
	cin >> num_large;

	cout << "Number of small rooms: 4" 
		<< num_small 
		<< endl;
	cout << "Number of large rooms: $" 
		<< num_large 
		<< endl;
	cout << "Price per small rooms: $" 
		<< price_small 
		<< endl;
	cout << "Price per large rooms: $" 
		<< price_large 
		<< endl;
	cout << "Cost: $" 
		<< (num_small * price_small) + (num_large * price_large) 
		<< endl;
	cout << "Tax: $" 
		<< ((num_small * price_small) + (num_large * price_large)) * 0.06 
		<< endl;
	cout << "=========================\n";
	cout << "Total estimate: $" 
		<< (num_small * price_small) + (num_large * price_large) + (((num_small * price_small) + (num_large * price_large)) * 0.06)
		<< endl;

	return 0;
}

