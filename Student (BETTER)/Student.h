#pragma once
#include <iostream>
using namespace std;
#include "studentPhone.h"
#include "studentDate.h"
#include "MyString.h"
class Student {
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);
private:
	MyString firstName;
	MyString lastName;
	MyString idNumber;
	Date birthDate;
	Phone phone;
public:
	Student(const MyString&, const MyString&,
		const MyString&, const Date&, const Phone&);
	Student(const Student&);
	Student();
	~Student();
	void setValues(const MyString&, const MyString&, const Date&, const Phone&);
	void setFirstName(const MyString&);
	void setLastName(const MyString&);
	void setId(const MyString&);
	void setPhone(const Phone&);
	void setDate(const Date&);
	void setValues(const MyString& tempFirstName, const MyString& tempLastName,
		const MyString& tempId, const Date& tempDate,
		const Phone& tempPhone);
	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getId() const;
	const Date& getDate() const;
	const Phone& getPhone()const;
	Student& operator=(const Student&);
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&); 
};//end class Student

