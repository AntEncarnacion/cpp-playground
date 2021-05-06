#include <iostream>
using namespace std;
#include "StudentList.h"
istream& operator>>(istream& input, studentList& tempStudentList) {
	int i, n;
	Student tempStudent;
	cout << "Entre el numero de estudiantes:";
	input >> n;
	for (i = 0; i < n; i++) {
		input >> tempStudent;
		while (tempStudentList.searchStudent(tempStudent) && (tempStudentList.size != 0)) {
			cout << "Entre de nuevo el estudiante #[" << i + 1 << "]:\n";
			input >> tempStudent;
		} //end while
		tempStudentList.stdt[i] = tempStudent;
		tempStudentList.size++;
		tempStudentList.sortStudent();
	}//end for
	return input;
}//end function operator>>
ostream& operator<<(ostream& output, const studentList& tempStudentList) {
	int i;
	for (i = 0; i < tempStudentList.getSize(); i++) {
		cout << "Student[" << i + 1 << "]: " << endl;
		output << tempStudentList.stdt[i];
	}//end for
	cout << endl;
	return output;
}//end function operator <<
void studentList::sortStudent() {
	Student temp;
	bool switched = true;
	for (int pass = 0; pass < (this->getSize() - 1) && switched; pass++) {
		switched = false;
		for (int j = 0; j < (this->getSize() - pass - 1); j++) {
			if ((*this)[j].getId() > (*this)[j + 1].getId()) {
				temp = stdt[j];
				stdt[j] = stdt[j + 1];
				stdt[j + 1] = temp;
				switched = true;
			}//end if
		}//end for
	}//end for
}//end sortStudent
studentList::studentList() {
	size = 0;
}//end constructor
studentList::studentList(const studentList& tempStudentList) :size(tempStudentList.size)
{
	for (int i = 0; i < getSize(); i++) {
		*(stdt + i) = *(tempStudentList.stdt + i);
	}//end for
}//end constructor
studentList::~studentList() {
}//end destructor
studentList& studentList::operator=(const studentList& tempStudentList) {
	int i;
	size = tempStudentList.size;
	for (i = 0; i < getSize(); i++) {
		stdt[i] = tempStudentList.stdt[i];
	}//end for
	return *this;
}//end function operator =
void studentList::operator+=(const Student& tempStudent) {
	if (!isFull() && !searchStudent(tempStudent)) {
		*(stdt + size) = tempStudent;
		this->size++;
		this->sortStudent();
	} //end if
	else {
		cout << "Array is full or repeatedly id " << endl;
	} //end else
}//end function operator +=
bool studentList::searchStudent(const MyString& tempId) const {
	bool found = false;
	MyString temp;
	for (int i = 0; i < this->getSize(); i++) {
		temp = stdt[i].getId();
		if (temp == tempId)
		{
			found = true;
			i = size;
		}//end if
	}//end for
	return found;
}//end function
bool studentList::searchStudent(const char* tempId) const {
	bool found = false;
	MyString temp;
	for (int i = 0; i < this->getSize(); i++) {
		temp = stdt[i].getId();
		cout << temp << " " << tempId << endl;
		if (temp == tempId) {
			found = true;
			i = size;
		}//end if
	}//end for
	return found;
}//end function
bool studentList::searchStudent(const Student& tempStudent) const {
	bool found = false;
	for (int i = 0; i < this->getSize(); i++) {
		if (stdt[i].getId() == tempStudent.getId()) {
			found = true;
			i = size;
		}//end if
	}//end for
	return found;
}//end function
int studentList::subscriptStudent(const MyString& tempId) const {
	int subscript = -1;
	MyString temp;
	for (int i = 0; i < this->getSize(); i++) {
		temp = stdt[i].getId();
		if (temp == tempId) {
			subscript = i;
			i = size;
		}//end if
	}//end for
	return subscript;
}//end function
int studentList::subscriptStudent(const char* tempId) const {
	int subscript = -1;
	MyString temp;
	for (int i = 0; i < this->getSize(); i++) {
		temp = stdt[i].getId();
		if (temp == tempId) {
			subscript = i;
			i = size;
		}//end if
	}//end for
	return subscript;
}//end function
int studentList::subscriptStudent(const Student& tempStudent) const {
	int subscript = -1;
	for (int i = 0; i < this->getSize(); i++) {
		if (stdt[i].getId() == tempStudent.getId()) {
			subscript = i;
			i = size;
		}//end if
	}//end for
	return subscript;
}//end function
void studentList::operator-=(const MyString& tempId) {
	int subscript;
	if (!isEmpty() && searchStudent(tempId)) {
		subscript = subscriptStudent(tempId);
		for (int i = subscript; i < getSize() - 1; i++) {
			*(stdt + i) = *(stdt + (i + 1));
		}//end for
		size--;
	}//ed if
	else
	{
		cout << "Invalid id" << endl;
	}//end else
}//end function operator -=
void studentList::operator-=(const char* tempId) {
	int subscript;
	if (!isEmpty() && searchStudent(tempId)) {
		subscript = subscriptStudent(tempId);
		for (int i = subscript; i < getSize() - 1; i++) {
			*(stdt + i) = *(stdt + (i + 1));
		}//end for
		size--;
	}//end if
	else {
		cout << "Invalid id" << endl;
	}//end else
}//end function operator -=
bool studentList::isEmpty() const {
	return(this->size == 0);
}//end function
bool studentList::isFull() const {
	return(this->size == MAX_STD);
}//end function
int studentList::getSize() const {
	return (this->size);
}//end function
Student& studentList::operator[] (int subscript) {
	if ((subscript < 0) || (subscript >= getSize())) {
		cout << "Error: Subscript " << subscript << " out of range \n";
		exit(1);
	}//end if
	return stdt[subscript];
}//end function operator []
Student studentList::operator[] (int subscript) const
{
	if ((subscript < 0) || (subscript >= getSize())) {
		cout << "Error: Subscript " << subscript << " out of range \n";
		exit(1);
	}//end if
	return stdt[subscript];
}//end function operator []