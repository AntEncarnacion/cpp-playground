#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class CSVParser
{
private:
	vector<vector<string>> parsedCsv;		//2 Dimensional vector that stores CSV rows and columns.
public:
	CSVParser();	//Default constructor that extracts data from CSV file.
	~CSVParser();	//Destructor
	int size();	//Returns the quantity of rows.

	//This proxy class is neccesary for overloading the [][] operator.
	class Proxy {
	public:
		Proxy(vector<string> vector) : vector(vector) { }

		string operator[](int index) {
			return vector[index];
		}
	private:
		vector<string> vector;
	};

	Proxy operator[](int index) 
	{
		return Proxy(parsedCsv[index]);
	}
};