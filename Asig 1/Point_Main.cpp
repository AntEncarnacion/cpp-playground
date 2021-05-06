/*Anthony Y. Encarnacion Torres #113862
 Jean Marco Ambert # 108124
 Jan Carlos Barreto Torres #127484*/
#include <iostream>
using namespace std;
#include "Point_Class.h"

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
	system("pause");

	return 0;
}

/*Ingrese la coordenada en x en el primer punto
5
Ingrese la coordenada en y en el primer punto
6
Ingrese la coordenada en x en el segundo punto
-3
Ingrese la coordenada en y en el segundo punto
2
El punto 1 se encuentra en el eje de y
El punto 2 se encuentra en el cuadrante 2
La distancia entre el primer punto y el segundo punto es 5
Press any key to continue . . .*/
