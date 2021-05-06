#include "Runner.h"
#include "MyString.h"
#include "Time.hpp"
#include <iostream>
using namespace std;


Runner::Runner()
{
	this->name = " ";
	time.setHours(0);
	time.setMinutes(0);
	time.setSeconds(0);
}
Runner::Runner(MyString name, Time time)
{
	this->name = name;
	this->time.setHours(time.getHours());
	this->time.setMinutes(time.getMinutes());
	this->time.setSeconds(time.getSeconds());
}
Runner::Runner(MyString name, int hours, int minutes, int seconds)
{
	this->name = name;
	this->time.setHours(hours);
	this->time.setMinutes(minutes);
	this->time.setSeconds(seconds);
}
Runner::Runner(const Runner& anRunner)
{
	name = anRunner.getName();
	time = anRunner.getTime();
}

void Runner::setName(MyString name)
{
	this->name = name;
}


void Runner::setTime(Time atime)
{
	this->time = atime;
}

MyString Runner::getName() const
{
	return this->name;
}

Time Runner::getTime()const
{
	return time;
}


ostream& operator << (ostream& strm, const Runner& obj)
{
	strm << "Name: " << obj.getName() << endl << obj.time << endl;
	return strm;
}

istream& operator >> (istream& strm, Runner& obj)
{
		cout << "Name: ";
		strm >> obj.name;
		strm >> obj.time;
		cout << endl;
	return strm;
}


bool Runner::operator > (const Runner& right)
{
	bool status;
	if (time > right.time)
		status = true;
	else
		status = false;
	return status;
}

bool Runner::operator < (const Runner& right)
{
	bool status;
	if (time < right.time)
		status = true;
	else
		status = false;
	return status;
}