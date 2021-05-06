#include<iostream>
using namespace std;
#include "StudentPhone.h"
#include "Student.h"
#include "StudentDate.h"
#include "MyString.h"
#include "SimpleVector.h"

const int SIZE = 50;
void getNumberStudent(int& size);

int main() {
	int size, choice = 0;
	getNumberStudent(size);
	SimpleVector<Student> clss1;

	for (int i = 0; i < size; i++)
	{
		cin >> clss1[i];
	}

	


	return 0;
}

void getNumberStudent(int& size)
{
	cout << "Ingrese la cantidad de estudiantes\n";
	cin >> size;
}