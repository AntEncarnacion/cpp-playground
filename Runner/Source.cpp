#include "Runner.h"

#include <iostream>

using namespace std;
const int SIZE = 50;
void getNumberRunners(int& size);
void sortRunner(Runner*, int);


int main()
{

	Runner* runner = nullptr;
	int size;

	getNumberRunners(size);

	runner = new Runner[size];


	for (int i = 0; i < size; i++)
	{
		cin >> runner[i];
	}

	sortRunner(runner, size);

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << runner[i] << endl;
	}


	delete[] runner;
	runner = nullptr;


	return 0;
}

void getNumberRunners(int& size)
{
	cout << "Please input number of runners:\n";
	cin >> size;
	cout << endl;
}

void sortRunner(Runner* runner, int size) 
{
	int i, j, min_idx;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (runner[j] < runner[min_idx])
				min_idx = j;

		swap(runner[min_idx], runner[i]);
	}
}//end sortStudent
