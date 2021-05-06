#include <iostream>
#include "Point.h"
using namespace std;

Point::Point()
{
	x = 0.0;
	y = 0.0;
}// Cocntructor
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}// Cocntructor
Point::Point(Point& aPoint)
{
	this->x = aPoint.getX();
	this->y = aPoint.getY();
}//Copy Constructor
Point::~Point()
{

}
double Point::getX() const
{
	return x;
}//Accessors
double Point::getY() const
{
	return y;
}
void Point::setX(double aX)
{
	x = aX;
}
void Point::setY(double aY)
{
	y = aY;
}// Mutators
void Point::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::display() const
{
	cout << "(" << x << ", " << y << ")" << endl;
}//Show point

bool Point::operator == (const Point& obj)const
{
	return (x == obj.x && y == obj.y);
}

ostream& operator << (ostream& strm, const Point& obj)
{
	strm << "(" << obj.x << ", " << obj.y << ")" << endl;
	return strm;
}
