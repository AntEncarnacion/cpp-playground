#include <iostream>
#include <string.h>
#include <ctype.h>
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
    cin.getline(linea, 50);
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
    letras = strlen(linea);
   cout << "El numero de letras en la linea es: " << letras << "\n\n";
}

void opt4()
{
  int i=0;
  char linea[50];
  char c;
  getstring(linea);

  for (i = 0; linea[i]!='\0'; ++i)
  {
    c=linea[i];
    putchar (toupper(c));
  }
    cout << c << "\n\n";
}

void opt5()
{
    char linea1[50];
    char linea2[50];
    int i;
    getstring(linea1);
   strcpy(linea2, linea1);
   cout << "El contenido del segundo string ahora es:  " << linea2 << "\n\n";
}

void opt6()
{
    char linea1[50], linea2[50], linea3[100];
    int i, j;
    getstring(linea1);
    getstring(linea2);

    strcpy(linea3, linea1);
    strcat(linea3, " ");
    strcat(linea3, linea2);

    cout << linea3 << "\n\n";
}
