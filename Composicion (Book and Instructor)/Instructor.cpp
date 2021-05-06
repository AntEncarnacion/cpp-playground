#include <iostream>
using namespace std;
#include "MyString.h"

#include "Instructor.h"

Instructor::Instructor()
{
	setLastName("");
	setFirstName("");
	setOfficeNumber("");
}

// Constructor 
Instructor::Instructor(MyString lname, MyString fname, MyString office)
{
	setLastName(lname);
	setFirstName(fname);
	setOfficeNumber(office);
}

Instructor::Instructor(const Instructor& anInstructor)
{
	lastName = anInstructor.getLastName();
	firstName = anInstructor.getFirstName();
	officeNumber = anInstructor.getOfficeNumber();
}

// set function 
void Instructor::set(MyString lname, MyString fname, MyString office)
{
	lastName = lname;
	firstName = fname;
	officeNumber = office;
}

void Instructor::setLastName(MyString lname)
{
	lastName = lname;
}

void Instructor::setFirstName(MyString fname)
{
	firstName = fname;
}

void Instructor::setOfficeNumber(MyString offnum)
{
	officeNumber = offnum;
}

MyString Instructor::getLastName()const
{
	return this->lastName;
}

MyString Instructor::getFirstName()const
{
	return this->firstName;
}

MyString Instructor::getOfficeNumber()const
{
	return this->officeNumber;
}

// print function 
void Instructor::print() const
{
	cout << "Last name: " << lastName << endl;
	cout << "First name: " << firstName << endl;
	cout << "Office number: " << officeNumber << endl;
}