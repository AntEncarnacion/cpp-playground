#pragma once
#include <iostream>
using namespace std;
#include "MyString.h"
#include "Time.hpp"

class Runner
{
private:
	MyString name;
	Time time;
public:
	Runner();
	Runner(MyString, Time);
	Runner(const Runner&);
	Runner(MyString, int, int, int);
	void setName(MyString);
	void setTime(Time);
	MyString getName() const;
	Time getTime()const;

	friend ostream& operator << (ostream&, const Runner&);
	friend istream& operator >> (istream&, Runner&);
	bool operator > (const Runner& right);
	bool operator < (const Runner& right);
};