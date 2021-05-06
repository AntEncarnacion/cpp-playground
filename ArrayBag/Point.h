#pragma once
#include<iostream>
using namespace::std;

class Point {

private:
	double x, y;
public:
	Point();
	Point(double x, double y); // Cocntructor
	Point(Point& aPoint); //Copy Constructor
	~Point();
	double getX() const;  //Accessors
	double getY() const;
	void setX(double aX);
	void setY(double aY); // Mutators
	void setXY(double x, double y);
	void display() const; //Show point

	bool operator == (const Point&) const;

	friend ostream& operator << (ostream& strm, const Point& obj);
	
};