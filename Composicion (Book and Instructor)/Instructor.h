#pragma once
#include <iostream>
//#include <string>
#include "MyString.h"
using namespace std;

// Instructor class 
class Instructor
{
private:
	MyString lastName;    // Last name 
	MyString firstName;   // First name 
	MyString officeNumber; // Office number 
public:
	// The default constructor stores empty MyStrings 
		// in the MyString objects. 
	Instructor();

	// Constructor 
	Instructor(MyString lname, MyString fname, MyString office);
	Instructor(const Instructor& anInstructor);

	// set function 
	void set(MyString lname, MyString fname, MyString office);
	void setLastName(MyString lname);
	void setFirstName(MyString fname);
	void setOfficeNumber(MyString offnum);

	MyString getLastName()const;
	MyString getFirstName()const;
	MyString getOfficeNumber()const;

	// print function 
	void print() const;
};