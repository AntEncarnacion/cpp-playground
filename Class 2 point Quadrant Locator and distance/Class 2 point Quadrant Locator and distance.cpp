#include <iostream>
#include <cmath>
using namespace std;

class Punto
{
private:
	int x1;
	int x2;
	int y1;
	int y2;

public:
	Punto();
	Punto(int, int, int, int);
	void setX(int, int);
	void setY(int, int);

	int getX1() const;
	int getX2() const;
	int getY1() const;
	int getY2() const;
	double getDistance() const;
	void display() const;
};

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

void Punto::setX(int xOne, int xTwo)
{
	x1 = xOne;
	x2 = xTwo;
}



void Punto::setY(int yOne, int yTwo)
{
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


int main()
{
	Punto coordenada;

	int CoordX1, CoordY1, CoordX2, CoordY2;

	cout << "Ingrese la coordenada en x en el primer punto\n";
	cin >> CoordX1;

	cout << "Ingrese la coordenada en y en el primer punto\n";
	cin >> CoordY1;

	cout << "Ingrese la coordenada en x en el segundo punto\n";
	cin >> CoordX2;

	cout << "Ingrese la coordenada en y en el segundo punto\n";
	cin >> CoordY2;

	coordenada.setX(CoordX1, CoordX2);
	coordenada.setY(CoordY1, CoordY2);
	
	coordenada.display();

	return 0;
}