#include "CSVParser.h"

//Default constructor that extracts data from CSV file.
CSVParser::CSVParser()
{
	ifstream  data("all_month.csv");
	string line;
	while (getline(data, line))
	{
		stringstream lineStream(line);
		string cell;
		vector<string> parsedRow;

		while (getline(lineStream, cell, ','))
		{
			parsedRow.push_back(cell);
		}

		parsedCsv.push_back(parsedRow);
	}
}

//Destructor.
CSVParser::~CSVParser()
{

}

//Returns the quantity of rows.
int CSVParser::size()
{
	return parsedCsv.size();
}