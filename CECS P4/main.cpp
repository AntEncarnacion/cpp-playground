#include <iostream>
#include <iomanip>
using namespace std;

int verificaMemoria(float *gastos){
     if (gastos == NULL)
	{
		cout << "Error allocating memory, bye!!!";
		return -1;
	}
	return 0;
}

void leerHarteras(float *gastos, int &numOfdata, int &totalGastos)
{
    for (int i = 0; i < numOfdata; i++)
	{
		cout << "Leyendo hartera " << i + 1;
		cout << " en posicion de memoria: " << gastos + i << " : ";
		cin >> *(gastos + i);
		totalGastos = totalGastos + *(gastos + i);
	}
}

void imprimeHarterasyTotal(float *gastos, int &numOfdata, int &totalGastos)
{
    for (int i = 0; i < numOfdata; i++)
    {
        cout << "\nHartera numero " << i + 1;
        cout << " en direccion de memoria: " << gastos + i;
        cout << " con valor de : ";
        cout << *(gastos + i);
    }
		cout << "\nEl total de gastos es: " << totalGastos << endl;
}

int main()
{
	float *gastos;
	int numOfdata, totalGastos = 0;
	cout << "Entre el numero total de fiestas: ";
	cin >> numOfdata;
	gastos = new float[numOfdata];

	if (-1 == verificaMemoria(gastos))
	{
	    cout << "End of main";
	    return -1;
	}

	cout << "Entre la factura de su hartera\n";
    leerHarteras(gastos, numOfdata, totalGastos);

	imprimeHarterasyTotal(gastos, numOfdata, totalGastos);

	delete[] gastos;
	return 0;
}

