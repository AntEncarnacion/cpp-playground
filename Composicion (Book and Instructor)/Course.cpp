#include <iostream>
#include "MyString.h"
#include "Instructor.h"
#include "TextBook.h"
#include "Course.h"
using namespace std;

Course::Course()
{
	courseName = "";
	instructor.setLastName("");
	instructor.setFirstName("");
	instructor.setOfficeNumber("");
	textbook.setTitle("");
	textbook.setAuthor("");
	textbook.setPublisher("");
}
Course::Course(MyString course, Instructor myInstructor, TextBook myTextBook)
{
	courseName = course;

	 //Assign the instructor. 
	instructor.setLastName(myInstructor.getLastName());
	instructor.setFirstName(myInstructor.getFirstName());
	instructor.setOfficeNumber(myInstructor.getOfficeNumber());
	 //Assign the textbook. 
	textbook.setTitle(myTextBook.getTitle());
	textbook.setAuthor(myTextBook.getAuthor());
	textbook.setPublisher(myTextBook.getPublisher());
}

Course::Course(MyString course, MyString instrLastName, MyString instrFirstName, MyString instrOffice, MyString textTitle, MyString author, MyString publisher)
{ // Assign the course name. 
	courseName = course;
	// Assign the instructor. 
	instructor.setLastName(instrLastName);
	instructor.setFirstName(instrFirstName);
	instructor.setOfficeNumber(instrOffice);

	// Assign the textbook. 
	textbook.setTitle(textTitle);
	textbook.setAuthor(author);
	textbook.setPublisher(publisher);
}

Course::Course(Course& aCourse)
{
	courseName = aCourse.getCourseName();
	instructor = aCourse.getInstructor();
	textbook = aCourse.getTextBook();
}

void Course::setCourseName(MyString aCourse)
{
	courseName = aCourse;
}

void Course::setInstructor(Instructor aInstructor)
{
	instructor = aInstructor;
}

void Course::setTextBook(TextBook aTextbook)
{
	textbook = aTextbook;
}

MyString Course::getCourseName() const
{
	return courseName;
}

Instructor Course::getInstructor() const
{
	return instructor;
}

TextBook Course::getTextBook() const
{
	return textbook;
}

// print function 
void Course::print() const
{
	cout << "Course name: " << courseName << endl << endl;
	cout << "Instructor Information:\n";
	instructor.print();
	cout << "\nTextbook Information:\n";
	textbook.print();
	cout << endl;
};
