#include <iostream>

using namespace std;

int minventas(double []);
int maxventas(double []);
double caltotal(double[]);
double calminval(double []);
double calmaxval(double []);

int main()
{
const int meses = 12;
double ventas[meses];
double total, minvalue, maxvalue;
char nombremeses[meses][11] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
int i, min, max;



cout << "ENTRE LAS VENTAS DE CADA MES:\n\n";

for(i = 0; i < meses; i++)
{
    cout << nombremeses[i] << ": $";
    cin >> ventas[i];
    while (ventas[i] < 0)
    {
        cout << "Por favor introduzca un valor mayor que 0.";
        cin >> ventas[i];
    }

    cout << '\n';
}

min = minventas(ventas);
max = maxventas(ventas);
minvalue = calminval(ventas);
maxvalue = calmaxval(ventas);
total = caltotal(ventas);

cout << "=========================================\nREPORTE DE VENTAS DEL AÑO\n=========================================\n";

for(i = 0; i < 8; i++)
{
    cout << nombremeses[i] << "\t\t\t==>\t" << ventas[i];

    if(minvalue != maxvalue)
    {
        if (ventas[i] == minvalue)
        {
            cout << "-";
        }
        else if(ventas[i] == maxvalue)
        {
            cout << "+";
        }
    }
    else if(minvalue == maxvalue)
    {
        cout << "+ -";
    }
    cout << '\n';
}

    cout << nombremeses[9] << "\t\t\t==>\t" << ventas[9];

    if(minvalue != maxvalue)
    {
        if (ventas[9] == minvalue)
        {
            cout << "-";
        }
        else if(ventas[9] == maxvalue)
        {
            cout << "+";
        }
    }
    else if(minvalue == maxvalue)
    {
        cout << "+ -";
    }
    cout << '\n';

    for(i = 10; i < 12; i++)
    {
        cout << nombremeses[i] << "\t\t==>\t" << ventas[i];

        if(minvalue != maxvalue)
        {
            if (ventas[i] == minvalue)
            {
                cout << "-";
            }
            else if(ventas[i] == maxvalue)
            {
                cout << "+";
            }
        }
        else if(minvalue == maxvalue)
        {
            cout << "+ -";
        }
        cout << '\n';
    }


cout << "RESUMEN\n\n";
cout << "Numero de meses con menor ventas: " << min << '\n';
cout << "Numero de meses con mayor ventas: " << max << "\n\n";
cout << "TOTAL VENTAS DEL AÑO = $" << total << "\n\n";
cout << "=========================================";

return 0;
}

double caltotal(double ventas[])
{
int i;
double total = 0;
for (i = 0; i < 12; i++)
    {
        total = total + ventas[i];
    }
return total;
}

int minventas(double ventas[])
{
double minval;
int min = 0;
minval = ventas[0];

    for (int i = 0; i < 12; i++)
    {
    if (ventas[i] < minval)
        {
          minval = ventas[i];
          min = 0;
          min++;
        }
    else if(ventas[i] == minval)
        min++;
    }
return min;
}

int maxventas(double ventas[])
{
double maxval;
int max = 0;
maxval = ventas[0];

    for (int i = 0; i < 12; i++)
    {
    if (ventas[i] > maxval)
        {
          maxval = ventas[i];
          max = 0;
          max++;
        }
    else if(ventas[i] == maxval)
        max++;
    }
return max;
}

double calminval(double ventas[])
{
    double mn;
    mn = ventas[0];

    for(int i=1;i<10;i++)
	{
		if(mn>ventas[i])
		{
			mn=ventas[i];
		}
	}
    return mn;
}

double calmaxval(double ventas[])
{
    double mx;
    mx = ventas[0];

    for(int i=1;i<10;i++)
	{
		if(mx<ventas[i])
		{
			mx=ventas[i];
		}

	}
    return mx;
}

/* ENTRE LAS VENTAS DE CADA MES:

Enero: $1

Febrero: $1

Marzo: $1

Abril: $1

Mayo: $1

Junio: $1

Julio: $1

Agosto: $1

Septiembre: $1

Octubre: $1

Noviembre: $1

Diciembre: $1

=========================================
REPORTE DE VENTAS DEL A╤O
=========================================
Enero                   ==>     1+ -
Febrero                 ==>     1+ -
Marzo                   ==>     1+ -
Abril                   ==>     1+ -
Mayo                    ==>     1+ -
Junio                   ==>     1+ -
Julio                   ==>     1+ -
Agosto                  ==>     1+ -
Octubre                 ==>     1+ -
Noviembre               ==>     1+ -
Diciembre               ==>     1+ -
RESUMEN

Numero de meses con menor ventas: 12
Numero de meses con mayor ventas: 12

TOTAL VENTAS DEL A╤O = $12

=========================================
ENTRE LAS VENTAS DE CADA MES:

Enero: $1

Febrero: $2

Marzo: $3

Abril: $2

Mayo: $2

Junio: $2

Julio: $2

Agosto: $2

Septiembre: $2

Octubre: $2

Noviembre: $2

Diciembre: $2

=========================================
REPORTE DE VENTAS DEL A├æO
=========================================
Enero                   ==>     1-
Febrero                 ==>     2
Marzo                   ==>     3+
Abril                   ==>     2
Mayo                    ==>     2
Junio                   ==>     2
Julio                   ==>     2
Agosto                  ==>     2
Octubre                 ==>     2
Noviembre               ==>     2
Diciembre               ==>     2
RESUMEN

Numero de meses con menor ventas: 1
Numero de meses con mayor ventas: 1

TOTAL VENTAS DEL A├æO = $24

=========================================*/
