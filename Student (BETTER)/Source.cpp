#include<iostream>
using namespace std;
#include "StudentPhone.h"
#include "Student.h"
#include "StudentDate.h"
#include "MyString.h"
#include "StudentList.h"
int main() {
	studentList st1, st2;
	char id[25];
	int index;
	Student t;
	cin >> st1; //Entra la informacion de los estudiantes
	cout << "Entre el indice del estudiante: ";
	cin >> index;
	cout << "Estudiante actual [" << index << "]: " << endl;
	cout << st1[index] << endl; //Imprime una localidad especifica
	cout << "Entre el nuevo estudiante:";
	cin >> t;
	st1[index] = t; //Modifica un estudiante
	cout << st1; //Imprime el contenido del arreglo
	t = st1[0]; //toma la informacion del primer estudiante
	cout << t; //Imprime el estudiante
	cout << "Entre el nuevo estudiante:";
	cin >> t;
	st1 += t; //Anade un estudiante nuevo al final del arreglo
	cout << st1; //Imprime el arreglo
	cout << "Entre el id a eliminar:";
	cin >> id;
	st1 -= id; //Si id existe elimina un estudiante
	st2 = st1; //Operador de asignar
	cout << "Original:\n" << st1;
	cout << "Modificado:\n" << st2;
	studentList st3(st1); // Copy constructor
	cout << "COPY:" << st3;
	return 0;
}//endmain
