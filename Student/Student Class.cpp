#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
	string name;
	long int id;
	int finalGrade;
public:
	Student();
	Student(string n, long int ident, int grade);
	~Student();
	void setName(string n);
	void setID(long int ident);
	void setFinalGrade(int grade);
	string getName() const;
	long int getID() const;
	int getFinalGrade() const;
};