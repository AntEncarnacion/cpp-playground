#include <iostream>
using namespace std;

// Rectangle class declaration. 
class Rectangle
{
private:
	double width;
	double length;


public:
	Rectangle();
	Rectangle(double, double);
	void setWidth(double);
	void setLength(double);
	double getWidth() const;
	double getLength() const;
	double getArea() const;
	double getPerimeter() const;
	void display()const;


};


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

void Rectangle::setWidth(double w)
{
	width = w;
}

void Rectangle::setLength(double len)
{
	length = len;
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




int main()
{
	Rectangle box;
	Rectangle box1(4, 5);

	double rectLength;
	double rectWidth;

	cout << "This program will calculate the area of a\n";
	cout << "rectangle. What is the width? ";

	cin >> rectWidth;
	cout << "What is the length? ";
	cin >> rectLength;

	box.setWidth(rectWidth);
	box.setLength(rectLength);
	box.display();
	box1.display();

	system("pause");
	return 0;

}