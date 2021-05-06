#include <iostream>
using namespace std;
#include "Rectangle_Class.h"

Rectangle::Rectangle()
{
	length = 1.0;
	width = 1.0;
}

Rectangle::Rectangle(double w, double l)

{
	width = w;
	length = l;
}

Rectangle::~Rectangle() {

}

void Rectangle::setWidth(double w)
{
	if (w >= 0)
		 width = w;
	else
		 {
		 cout << "Invalid width\n";
		 exit(EXIT_FAILURE);
		 }
}

void Rectangle::setLength(double len)
{
	if (len >= 0)
		length = len;
	else
	{
		cout << "Invalid length\n";
		exit(EXIT_FAILURE);
	}
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getLength() const
{
	return length;
}
double Rectangle::getArea() const
{
	return width * length;
}



double Rectangle::getPerimeter() const
{
	return  2 * getLength() + 2 * getWidth();
}

void Rectangle::display() const
{
	cout << "Here is the rectangle's data:\n";
	cout << "Width: " << getWidth() << endl;
	cout << "Length: " << getLength() << endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter:" << getPerimeter() << endl;
}