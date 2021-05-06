/*Anthony Y. Encarnacion Torres #113862
 Jean Marco Ambert # 108124
 Jan Carlos Barreto Torres #127484*/
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
	~Rectangle();
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

Rectangle::~Rectangle() {}

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
/*This program will calculate the area of a
rectangle. What is the width? 10
What is the length? 5
Here is the rectangle's data:
Width: 10
Length: 5
Area: 50
Perimeter:30
Press any key to continue . . .*/
