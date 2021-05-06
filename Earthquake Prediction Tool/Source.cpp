#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "CSVParser.h"

//Puerto Rico coordinates.
const static float maxY = 18.728357, minY = 17.627644, maxX = -65.415467, minX = -67.703205;

//For clasifying quakes of different magintudes. These are used as indexes for vectors.
enum
{
	LV1, LV2, LV3, LV4
};

//Functions that are used various times throughout the code.
void splitDate(string s, int& day, int& month, int& year);	//Splits the date string into three integers.
float calculateProbability(const vector<int>&, float);	//Does a very rough calculation of the probability of an earthquake happening.
int quantityQuakes(const vector<int>&);	//Counts how many quakes happened during the scope.
void printForecast(const vector<vector<int>>&, int);	//Prints out earthquake forecast.

int main()
{
	CSVParser parsedCsv;

	//Stores date data.
	string date;
	int day, month, year;

	//Vectors for storing data from different dates.
	vector<vector<int>> countQuakes(4);
	vector<int> tempCount(4), maxQuakesInDay(4);



	//This loop checks every row in the CSV except the row containing the header.
	for (int i = 1; i < parsedCsv.size(); i++)
	{

		//Temporary variables for storing the date from the previous iteration to compare it with the current iteration.
		string tempDate = "00/00/0000";
		int tempDay, tempMonth, tempYear;
		splitDate(tempDate, tempDay, tempMonth, tempYear);

		//Checks if row is within specified coordinates
		if (stof(parsedCsv[i][1]) >= minY && stof(parsedCsv[i][1]) <= maxY && stof(parsedCsv[i][2]) >= minX && stof(parsedCsv[i][2]) <= maxX)
		{
			date = parsedCsv[i][0];
			splitDate(date, day, month, year);

			//In the first iteration of this loop the temp variables will be empty. This initializes them.
			if (i == 1)
			{
				tempDate = date;
				splitDate(tempDate, tempDay, tempMonth, tempYear);
			}

			//This checks if the date has changed and if so it stores the counts and then resets them to count again for the new date.
			if (day != tempDay || month != tempMonth || year != tempYear)
			{

				countQuakes[LV1].push_back(tempCount[LV1]);
				countQuakes[LV2].push_back(tempCount[LV2]);
				countQuakes[LV3].push_back(tempCount[LV3]);
				countQuakes[LV4].push_back(tempCount[LV4]);
				tempCount[LV1] = 0, tempCount[LV2] = 0, tempCount[LV3] = 0, tempCount[LV4] = 0;

				date = parsedCsv[i][0];
				splitDate(date, day, month, year);
			}

			//Used for comparing the current iteration with the next one.
			tempDate = parsedCsv[i][0];
			splitDate(tempDate, tempDay, tempMonth, tempYear);

			//Data count
			if (stof(parsedCsv[i][4]) < 3)
				tempCount[LV1]++;
			else if (stof(parsedCsv[i][4]) < 5)
				tempCount[LV2]++;
			else if (stof(parsedCsv[i][4]) < 6)
				tempCount[LV3]++;
			else
				tempCount[LV4]++;
		}
	}

	//Stores in a variable the maximum amount of an earthquakes of a certain magnitude in a day.
	for (int i = 0; i < countQuakes[LV1].size(); i++)
		if (countQuakes[LV1][i] > maxQuakesInDay[LV1])
			maxQuakesInDay[LV1] = countQuakes[LV1][i];
	for (int i = 0; i < countQuakes[LV2].size(); i++)
		if (countQuakes[LV2][i] > maxQuakesInDay[LV2])
			maxQuakesInDay[LV2] = countQuakes[LV2][i];
	for (int i = 0; i < countQuakes[LV3].size(); i++)
		if (countQuakes[LV3][i] > maxQuakesInDay[LV3])
			maxQuakesInDay[LV3] = countQuakes[LV3][i];
	for (int i = 0; i < countQuakes[LV4].size(); i++)
		if (countQuakes[LV4][i] > maxQuakesInDay[LV3])
			maxQuakesInDay[LV4] = countQuakes[LV4][i];

	//Forecast for the next 7 days.
	cout << "Based on accumulated data from the past month here is the earthquake forecast for the next week\n" << endl;

	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY1" << endl;
	printForecast(countQuakes, 30.0);
	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY2" << endl;
	printForecast(countQuakes, 31.0);
	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY3" << endl; 
	printForecast(countQuakes, 32.0);
	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY4" << endl; 
	printForecast(countQuakes, 33.0);
	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY5" << endl; 
	printForecast(countQuakes, 34.0);
	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY6" << endl; 
	printForecast(countQuakes, 35.0);
	cout << endl << "##################################################################################" << endl << endl;
	cout << "DAY7" << endl; 
	printForecast(countQuakes, 36.0);
	cout << endl << "##################################################################################" << endl << endl;

	return 0;
}

//Splits date into three integers.
void splitDate(string s, int& day, int& month, int& year)
{
	char c;
	stringstream(s) >> year >> c >> month >> c >> day;
}

//Makes a very rough calculation of probability of quakes.
float calculateProbability(const vector<int>& countQuakes, float numDays)
{
	int sum = 0;
	for (int i = 0; i < countQuakes.size(); i++)
	{
		float temp = ((countQuakes[i] * 1.0) / 1.0);

		sum += temp;
	}

	if (sum > 30)
		return 100;
	else
		return (sum / numDays * 100.0);
}

//Counts the total amount of quakes.
int quantityQuakes(const vector<int>& countQuakes)
{
	int sum = 0;
	for (int i = 0; i < countQuakes.size(); i++)
	{
		float temp = ((countQuakes[i] * 1.0) / 1.0);

		sum += temp;
	}

	return sum;
}

//Prints out a forecast.
void printForecast(const vector<vector<int>>& countQuakes, int numDays)
{
	cout << "Chances of an earthquake less than magnitude 3.0 are:\n" << calculateProbability(countQuakes[LV1], numDays) << "%" << endl
		<< "Quantity in the past month: " << quantityQuakes(countQuakes[LV1]) << endl;

	cout << "Chances of an earthquake between magnitudes 3.0 and 5.0 are:\n" << calculateProbability(countQuakes[LV2], numDays) << "%" << endl
		<< "Quantity in the past month: " << quantityQuakes(countQuakes[LV2]) << endl;

	cout << "Chances of an earthquake between magnitudes 5.0 and 6.0 are:\n" << calculateProbability(countQuakes[LV3], numDays) << "%" << endl
		<< "Quantity in the past month: " << quantityQuakes(countQuakes[LV3]) << endl;

	cout << "Chances of an earthquake more than magnitude 6.0 are:\n" << calculateProbability(countQuakes[LV4], numDays) << "%" << endl
		<< "Quantity in the past month: " << quantityQuakes(countQuakes[LV4]) << endl << endl;
}