#include<iostream>
#include "MyString.h"
using namespace::std;
#include "Student.h"
ostream& operator<<(ostream& output, const Student& tempStudent)
{
	output << "First Name:" << tempStudent.firstName << endl;
	output << "Last Name:" << tempStudent.lastName << endl;
	output << "Phone:" << tempStudent.phone << endl;
	output << "Birthdate:" << tempStudent.birthDate << endl;
	return output;
}//end function operator<<
istream& operator>>(istream& input, Student& tempStudent)
{
	cout << "Enter first name: ";
	input >> tempStudent.firstName;
	cout << "Enter last name:";
	input >> tempStudent.lastName;
	cout << "Enter id:";
	input >> tempStudent.idNumber;
	cout << "Enter phone:";
	input >> tempStudent.phone;
	cout << "Enter birthday:";
	input >> tempStudent.birthDate;
	return input;
}//end function operator >>
Student::Student() :firstName("Juan"), lastName("Del pueblo"),
idNumber("12345"), birthDate(), phone() {
}//end Student
Student::Student(const MyString& tempFirstName,
	const MyString& tempLastName, const MyString& tempId,
	const Date& tempBirthDate, const Phone& tempPhone) : firstName(tempFirstName),
	lastName(tempLastName), idNumber(tempId), birthDate(tempBirthDate), phone(tempPhone)
{
}//end Student
Student::Student(const Student& tempStudent) : firstName(tempStudent.firstName),
lastName(tempStudent.lastName), idNumber(tempStudent.idNumber), birthDate(tempStudent.birthDate),
phone(tempStudent.phone)
{
}//end Student
Student::~Student()
{
	cout << "Student object destructor" << endl;
}//end Student destructor
void Student::setValues(const MyString& tempFirstName, const MyString& tempLastName,
	const Date& tempDate, const Phone& tempPhone) {
	setFirstName(tempFirstName);
	setLastName(tempLastName);
	setDate(tempDate);
	setPhone(tempPhone);
} //end setValues
void Student::setFirstName(const MyString& tempFirstName)
{
	firstName = tempFirstName;
}//end setFirstName
void Student::setLastName(const MyString& tempLastName)
{
	lastName = tempLastName;
}//set setlastName
void Student::setId(const MyString& tempId)
{
	idNumber = tempId;
}//set setId
void Student::setPhone(const Phone& tempPhone)
{
	phone.setAreaCode(tempPhone.getAreaCode());
	phone.setExchange(tempPhone.getExchange());
	phone.setLine(tempPhone.getLine());
}//end setPhone
void Student::setDate(const Date& tempDate)
{
	birthDate.setMonth(tempDate.getMonth());
	birthDate.setDay(tempDate.getDay());
	birthDate.setYear(tempDate.getYear());
}//end setDate
void Student::setValues(const MyString& tempFirstName, const MyString& tempLastName,
	const MyString& tempId, const Date& tempDate,
	const Phone& tempPhone) {
	setFirstName(tempFirstName);
	setLastName(tempLastName);
	setId(tempId);
	setDate(tempDate);
	setPhone(tempPhone);
} //end setValues
const MyString& Student::getFirstName() const
{
	return this->firstName;
}//end firstName
const MyString& Student::getLastName() const
{
	return this->lastName;
}//end getlastName
const MyString& Student::getId() const
{
	return this->idNumber;
}//end getId
const Phone& Student::getPhone()const
{
	return this->phone;
}//end getPhone
const Date& Student::getDate()const
{
	return this->birthDate;
}//end getPhone

Student& Student::operator=(const Student& tempStudent) {
	this->firstName = tempStudent.getFirstName();
	this->lastName = tempStudent.getLastName();
	this->idNumber = tempStudent.getId();
	this->birthDate = tempStudent.getDate();
	this->phone = tempStudent.getPhone();
	return *this;
}//end function operator=