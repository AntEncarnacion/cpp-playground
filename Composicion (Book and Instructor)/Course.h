#pragma once
 #include <iostream>
 //#include <string>
#include "MyString.h"
#include "Instructor.h"
 #include "TextBook.h"
 using namespace std;

 class Course
 {
 private:
	 MyString courseName;     // Course name 
	 Instructor instructor; // Instructor 
	 TextBook textbook;     // Textbook 
 public:
	 // Constructor 
	 Course();
	 Course(MyString, Instructor, TextBook);
	 Course(MyString course, MyString instrLastName, 
		 MyString instrFirstName, MyString instrOffice, 
		 MyString textTitle, MyString author, MyString publisher);
	 Course(Course&);
	 void setCourseName(MyString);
	 void setInstructor(Instructor);
	 void setTextBook(TextBook);
	 MyString getCourseName() const;
	 Instructor getInstructor() const;
	 TextBook getTextBook() const;
	 // print function 
	 void print() const;

 };
