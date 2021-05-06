#include <iostream>

using namespace std;

void opt1();
void opt2();
void opt3();
void opt4();
void opt5();
void opt6();

int main()
{
int opt;

while (opt != 7)
{
cout << "MENU PRINCIPAl\n\n"
<< "1. Contar el numero de vocales en un string\n"
<< "2. Contar el numero de consonantes en un string\n"
<< "3. Contar el numero de letras en un string\n"
<< "4. Convertir en mayuscula todas las letras de un string.\n"
<< "5. Copiar un string en otro string\n"
<< "6. Anexar un string al final de otro string\n"
<< "7. Fin\n\n"
<< "Entre el numero de la opcion deseada: ";

cin >> opt;
cin.ignore();

if (opt == 1)
opt1();
else if (opt == 2)
opt2();
else if (opt == 3)
opt3();
else if (opt == 4)
opt4();
else if (opt == 5)
opt5();
else if (opt == 6)
opt6();
else if(opt == 7)

return 0;
}
}

void getstring(char linea[])
{
    cout << "Entre una palabra, frase u oracion: ";
    cin.getline(linea, 50, '\n');

}

void opt1()
{
    char linea[50];
    int vocales;
    vocales = 0;

   getstring(linea);
   for(int i = 0; linea[i]!='\0'; ++i)
    {
        if(linea[i]=='a' || linea[i]=='e' || linea[i]=='i' ||
           linea[i]=='o' || linea[i]=='u' || linea[i]=='A' ||
           linea[i]=='E' || linea[i]=='I' || linea[i]=='O' ||
           linea[i]=='U')
        {
            ++vocales;
        }
    }
   cout << "El numero de vocales en la linea es: " << vocales << "\n\n";
}

void opt2()
{
    char linea[50];
    int consonantes;
    consonantes = 0;

    getstring(linea);
  for(int i = 0; linea[i]!='\0'; ++i)
    {
       if(linea[i]=='a' || linea[i]=='e' || linea[i]=='i' ||
           linea[i]=='o' || linea[i]=='u' || linea[i]=='A' ||
           linea[i]=='E' || linea[i]=='I' || linea[i]=='O' ||
           linea[i]=='U');
        else if((linea[i]>='a'&& linea[i]<='z') || (linea[i]>='A'&& linea[i]<='Z'))
        {
            ++consonantes;
        }
    }
   cout << "El numero de consonantes en la linea es: " << consonantes << "\n\n";
}

void opt3()
{
char linea[50];
    int letras;
    letras = 0;

    getstring(linea);
  for(int i = 0; linea[i]!='\0'; ++i)
    {
        if ((linea[i]>='a'&& linea[i]<='z') || (linea[i]>='A'&& linea[i]<='Z'))
        {
            ++letras;
        }
    }
   cout << "El numero de letras en la linea es: " << letras << "\n\n";
}

void opt4()
{
char linea[50];

    getstring(linea);
 for (int i = 0; i < linea[i]; i++)
    {
		if (linea[i] >= 'a' && linea[i] <= 'z')
			linea[i] = linea[i] - 32;
			    cout << linea[i];
    }
    cout << "\n\n";
}

void opt5()
{
    char linea1[50];
    char linea2[50];
    int i;
    getstring(linea1);
    for(i = 0; linea1[i] != '\0'; i++)
        linea2[i] = linea1[i];
    linea2[i] = '\0';
   cout << "El contenido del segundo string ahora es:  "<<linea2 << "\n\n";
}

void opt6()
{
    char linea1[100], linea2[50];
    int i, j;
    getstring(linea1);

    getstring(linea2);

    for(i=0; linea1[i]!='\0'; ++i);
    {
    linea1[i] = ' ';
    i++;
    for(j=0; linea2[j]!='\0'; ++j, ++i)
   {
      linea1[i]=linea2[j];
   }
    linea1[i]='\0';
    }
    cout << linea1 << "\n\n";
}

/*MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada: 1
Entre una palabra, frase u oracion: Hola
El numero de vocales en la linea es: 2

MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada: 2
Entre una palabra, frase u oracion: Hola
El numero de consonantes en la linea es: 2

MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada: 3
Entre una palabra, frase u oracion: Hola
El numero de letras en la linea es: 4

MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada: 4
Entre una palabra, frase u oracion: hola
HOLA

MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada: 5
Entre una palabra, frase u oracion: Hola
El contenido del segundo string ahora es:  Hola

MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada: 6
Entre una palabra, frase u oracion: Hola
Entre una palabra, frase u oracion: Ricardo
Hola Ricardo

MENU PRINCIPAl

1. Contar el numero de vocales en un string
2. Contar el numero de consonantes en un string
3. Contar el numero de letras en un string
4. Convertir en mayuscula todas las letras de un string.
5. Copiar un string en otro string
6. Anexar un string al final de otro string
7. Fin

Entre el numero de la opcion deseada:*/
