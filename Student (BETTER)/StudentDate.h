#pragma once
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
private:
	int month, day, year;
	int checkDay(int) const; //utility function
	int checkMonth(int) const;
public:
	Date(int = 11, int = 17, int = 2010);
	Date(const Date&);
	~Date();
	void setValues(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	Date& operator=(const Date&);
}; //end class Date