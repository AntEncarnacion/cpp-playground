#include <iostream>
using namespace std;

#include "Course.h"
#include "Instructor.h"
#include "MyString.h"
#include "TextBook.h"

int main() {
	//Create a course object
	Course myCourse("Intro to computer science",
		"Kramer", "Shawn", "RH3010",	//Instructor info
		"Starting out with C++", "Gaddis",	//Textbook info
		"Addison-Wesley");	//TextBook publisher

	myCourse.print();
	cout << "####################\n";
	Instructor myInstructor("Claudia", "Talavera", "M206");
	TextBook myTextbook("Starting out with C++", "Gaddis", "Addison-Wesley");
	Course myCourse1("CECS2222", myInstructor, myTextbook);

	myInstructor.print();
	myTextbook.print();

	cout << "####################\n";
	myCourse1.getInstructor().print();

	return 0;
}