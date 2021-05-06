#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "ArrayBag.h"
#include "Point.h"

double sumX(ArrayBag<Point>& bag)
{
	double total = 0.0;

	for (int i = 0; i < bag.getMaxItems(); i++)
	{
		total += bag.getElement(i).getX();
	}
	return total;
}

double sumY(ArrayBag<Point>& bag)
{
	double total = 0.0;

	for (int i = 0; i < bag.getMaxItems(); i++)
	{
		total += bag.getElement(i).getY();
	}
	return total;
}

double sumXSquared(ArrayBag<Point>& bag)
{
	double total = 0.0;

	for (int i = 0; i < bag.getMaxItems(); i++)
	{
		total += (bag.getElement(i).getX() * bag.getElement(i).getX());
	}
	return total;
}

double sumYSquared(ArrayBag<Point>& bag)
{
	double total = 0.0;

	for (int i = 0; i < bag.getMaxItems(); i++)
	{
		total += (bag.getElement(i).getY() * bag.getElement(i).getY());
	}
	return total;
}

double sumProduct(ArrayBag<Point>& bag)
{
	double total = 0.0;

	for (int i = 0; i < bag.getMaxItems(); i++)
	{
		total += (bag.getElement(i).getX() * bag.getElement(i).getY());
	}
	return total;
}

double b(ArrayBag<Point>& bag)
{
	double total = 0.0;

	return ( (sumY(bag) * sumXSquared(bag)) - (sumX(bag) * sumProduct(bag)) ) / ( (bag.getMaxItems() * sumXSquared(bag)) - (sumX(bag) * sumX(bag)) );
}

double a(ArrayBag<Point>& bag)
{
	double total = 0.0;

	return ((bag.getMaxItems() * sumProduct(bag)) - (sumX(bag) * sumY(bag))) / ((bag.getMaxItems() * sumXSquared(bag)) - (sumX(bag) * sumX(bag)));
}

double r(ArrayBag<Point>& bag)
{
	return ( (bag.getMaxItems() * sumProduct(bag)) - (sumX(bag) * sumY(bag)) ) / sqrt( ((bag.getMaxItems() * sumXSquared(bag)) - pow(sumX(bag), 2)) * ((bag.getMaxItems() * sumYSquared(bag) - pow(sumY(bag), 2))));
}

int main()
{
	ArrayBag<Point> bagPoints;
	Point point;
	float x, y;
	cout << "Enter 8 points:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "X: ";
		cin >> x;
		cout << "Y:";
		cin >> y;
		point.setXY(x, y);
		bagPoints.add(point);
	}
	
	cout << "Table x = temp, y = % injured" << endl;

	for (int i = 0; i < bagPoints.getMaxItems(); i++)
	{
		cout << bagPoints.getElement(i) << endl;
	}

	cout << "LinReg\ny=ax+b" << endl
		<< "a = " << a(bagPoints) << endl
		<< "b = " << b(bagPoints) << endl
		<< "r^2 = " << pow(r(bagPoints), 2) << endl
		<< "r = " << r(bagPoints) << endl;


	return 0;
}

