#include <iostream>
#include <cmath>
using namespace std;
#include "Point_Class.h"

Punto::Punto()
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

Punto::Punto(int xOne, int xTwo, int yOne, int yTwo)
{
	x1 = xOne;
	x2 = xTwo;
	y1 = yOne;
	y2 = yTwo;

}

Punto::~Punto() {

}

void Punto::setX(int xOne, int xTwo)
{
	if (xOne >= 0 && xTwo >= 0) 
			x1 = xOne;
			x2 = xTwo;
}

void Punto::setY(int yOne, int yTwo)
{
	if (yOne >= 0 && yTwo >= 0)
		y1 = yOne;
		y2 = yTwo;
}


int Punto::getX1() const
{
	return x1;
}
int Punto::getX2() const
{
	return x2;
}

int Punto::getY1() const
{
	return y1;
}
int Punto::getY2() const
{
	return y2;
}
double Punto::getDistance() const
{
	return  sqrt(pow((getX2() - getX1()), 2.0) + pow((getY2() - getY1()), 2.0));
}


void Punto::display() const
{

	if (x1 > 0 && y1 > 0)
	{
		cout << "El punto 1 se encuentra en el cuadrante 1\n";

	}

	else if (x1 < 0 && y1 >0)
	{
		cout << "El punto 1 se encuentra en el cuadrante 2\n";

	}

	else if (x1 < 0 && y1 < 0)
	{
		cout << "El punto 1 se encuentra en el cuadrante 3\n";

	}

	else if (x1 > 0 && y1 < 0)
	{
		cout << "El punto 1 se encuentra en el cuadrante 4\n";

	}

	else if (x1 == 0 && y1 == 0)
	{
		cout << "El punto 1 se encuentra en el origen\n";
	}

	else if (x1 == 0 && y1 == 0)
	{
		cout << "El punto 1 se encuentra en el origen\n";
	}

	else if (x1 != 0 && y1 == 0)
	{
		cout << "El punto 1 se encuentra en el eje de x\n";
	}

	else if (y1 != 0 && x1 == 0)
	{
		cout << "El punto 1 se encuentra en el eje de y\n";
	}

	if (x2 > 0 && y2 > 0)
	{
		cout << "El punto 2 se encuentra en el cuadrante 1\n";

	}

	else if (x2 < 0 && y2 >0)
	{
		cout << "El punto 2 se encuentra en el cuadrante 2\n";

	}

	else if (x2 < 0 && y2 < 0)
	{
		cout << "El punto 2 se encuentra en el cuadrante 3\n";

	}

	else if (x2 > 0 && y2 < 0)
	{
		cout << "El punto 2 se encuentra en el cuadrante 4\n";

	}

	else if (x2 == 0 && y2 == 0)
	{
		cout << "El punto 2 se encuentra en el origen\n";
	}

	else if (x2 == 0 && y2 == 0)
	{
		cout << "El punto 2 se encuentra en el origen\n";
	}

	else if (x2 != 0 && y2 == 0)
	{
		cout << "El punto 2 se encuentra en el eje de x\n";
	}

	else if (y2 != 0 && x2 == 0)
	{
		cout << "El punto 2 se encuentra en el eje de y\n";
	}

	cout << "La distancia entre el primer punto y el segundo punto es " << getDistance() << endl;
}