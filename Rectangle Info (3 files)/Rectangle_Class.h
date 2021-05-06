#pragma once
// Rectangle class declaration. 
class Rectangle
{
private:
	double width;
	double length;

public:
	Rectangle();
	Rectangle(double, double);
	~Rectangle();
	void setWidth(double);
	void setLength(double);
	double getWidth() const;
	double getLength() const;
	double getArea() const;
	double getPerimeter() const;
	void display()const;
};