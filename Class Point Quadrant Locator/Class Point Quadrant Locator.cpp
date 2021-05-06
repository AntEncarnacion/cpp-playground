#include <iostream>
using namespace std;

class Punto
{
private:
	int x;
	int y;

public:
	Punto();
	Punto(int, int);
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
	void display() const;


};

Punto::Punto()
{
	x = 0;
	y = 0;
}

Punto::Punto(int x1, int y1)
{
	x = x1;
	y = y1;

}

void Punto::setX(int x1)
{
	x = x1;
}

void Punto::setY(int y1)
{
	y = y1;
}

int Punto::getX() const
{
	return x;
}

int Punto::getY() const
{
	return y;
}

void Punto::display() const
{

	if (x > 0 && y > 0)
	{
		cout << "Se encuentra en el cuadrante 1\n";

	}

	else if (x < 0 && y >0)
	{
		cout << "Se encuentra en el cuadrante 2\n";

	}

	else if (x < 0 && y < 0)
	{
		cout << "Se encuentra en el cuadrante 3\n";

	}

	else if (x > 0 && y < 0)
	{
		cout << "Se encuentra en el cuadrante 4\n";

	}

	else if (x == 0 && y == 0)
	{
		cout << "Se encuentra en el origen\n";
	}

	else if (x == 0 && y == 0)
	{
		cout << "Se encuentra en el origen\n";
	}

	else if (x != 0 && y == 0)
	{
		cout << " Se encuentra en el eje de x\n";
	}

	else if (y != 0 && x == 0)
	{
		cout << " Se encuentra en el eje de y\n";
	}

}


int main()
{
	Punto coordenada;

	int CoordX;
	int CoordY;

	cout << "Ingrese la coordenada en x\n";
	cin >> CoordX;

	cout << "Ingrese la coordenada en y\n";
	cin >> CoordY;

	coordenada.setX(CoordX);
	coordenada.setY(CoordY);
	coordenada.display();







	return 0;
}