#include <iostream> 
#include ".\SimpleVector.h" 
using namespace std;

int main()
{
	const int SIZE = 10; // Number of elements 
	int count;          // Loop counter 

	// Create a SimpleVector of ints. 
	SimpleVector<int> intTable(SIZE);


	// Store values in the two SimpleVectors. 
	for (count = 0; count < SIZE; count++)
	{
		cin >> intTable[count];
	}
	intTable.sortVector();

	// Display the values in the SimpleVectors. 
	cout << "These values are in intTable:\n";
	for (count = 0; count < SIZE; count++)
		cout << intTable[count] << " ";
	cout << endl;

	// Use the standard + operator on the elements. 
	cout << "\nAdding 5 to each element of intTable\n";
	for (count = 0; count < SIZE; count++)
	{
		intTable[count] = intTable[count] + 5;
	}

	// Display the values in the SimpleVectors. 
	cout << "These values are in intTable:\n";
	for (count = 0; count < SIZE; count++)
		cout << intTable[count] << " ";
	cout << endl;

	// Use the standard ++ operator on the elements. 
	cout << "\nIncrementing each element of intTable\n";
	for (count = 0; count < SIZE; count++)
	{
		intTable[count]++;
	}

	// Display the values in the SimpleVectors. 
	cout << "These values are in intTable:\n";
	for (count = 0; count < SIZE; count++)
		cout << intTable[count] << " ";
	cout << endl;

	return 0;
}