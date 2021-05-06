#include "Speakers.h"
#include <iostream>
#include "ArrayBag.h"
#include <string>
using namespace std;


void getNumbers(int& size);
void getData(int size, ArrayBag<Speakers>&);
void getChangeSpeaker(int index, ArrayBag<Speakers>&);
int fSpeaker(ArrayBag<Speakers>&, int size);
void display(ArrayBag<Speakers>&, int size);

int main()
{
	//Speakers *speaker = nullptr;
	//Speakers speaker;
	ArrayBag<Speakers> speakBag;
	//BagInterface<char> *Bag;
	//Bag = new ArrayBag<char>;


	int size = 0;
	int choice = 0;
	int index = 0;
	getNumbers(size);

	//speaker = new Speakers[size];



	while (choice != 4)
	{
		cout << "Menu Selection\n\n";
		cout << "1.Enter Speaker information\n";
		cout << "2.Change Speaker information\n";
		cout << "3.Display Speaker information\n";
		cout << "4.Exit program\n";
		cin >> choice;


		switch (choice)

		{
		case 1:
			getData(size, speakBag);
			break;

		case 2:
			index = fSpeaker(speakBag, size);
			getChangeSpeaker(index, speakBag);
			break;

		case 3:
			display(speakBag, size);

			break;

		}
	}


	//delete[] speaker;
	//speaker = nullptr;



	return 0;
}





void getData(int size, ArrayBag<Speakers>& bag)
{
	string name;
	string phone;
	string SpeakingTopic;
	double FeeRequired;
	Speakers speaker;

	for (int index = 0; index < size; index++)
	{
		cin.ignore();
		cout << "Ingrese el nombre\n";
		getline(cin, name);

		cout << "\nIngrese el numero de telefono\n";
		getline(cin, phone);

		cout << "\nIngrese el speakers topic\n";
		getline(cin, SpeakingTopic);

		cout << "\nIngrese la cuota requerida\n";
		cin >> FeeRequired;
		cin.ignore();

		speaker.setName(name);
		speaker.setPhone(phone);
		speaker.setSpeaking(SpeakingTopic);
		speaker.setFee(FeeRequired);
		bag.add(speaker);
	}


}

void getNumbers(int& size)
{
	cout << "Ingrese la cantidad de Speakers\n";
	cin >> size;
}

int fSpeaker(ArrayBag<Speakers>& speaker, int size)
{
	int i;
	string name;

	cin.ignore();
	cout << "Nombre de speaker para editar: ";
	getline(cin, name);

	for (i = 0; i < size; i++)
	{

		if (name == speaker.getElement(i).getName())
		{

			return i;

		}
	}

	cout << " Nombre Invalido:";

	return i;
}


void display(ArrayBag<Speakers>& speaker, int size)
{
	cout << "Speakers Bureau Information:\n";

	for (int index = 0; index < size; index++)
	{
		speaker.getElement(index).display();
	}
}


void getChangeSpeaker(int index, ArrayBag<Speakers>& bag)
{

	string name;
	string phone;
	string SpeakingTopic;
	double FeeRequired;


	cout << "  Ingresar nueva informacion para  " << bag.getElement(index).getName() << "        \n";

	cout << "Ingrese el nombre\n";
	getline(cin, name);


	cout << "Ingrese el # de telefono\n";
	getline(cin, phone);


	cout << "Ingrese el speakers topic\n";
	getline(cin, SpeakingTopic);


	cout << "Ingrese la cuota requerida\n";
	cin >> FeeRequired;

	bag.getElement(index).setName(name);
	bag.getElement(index).setPhone(phone);
	bag.getElement(index).setSpeaking(SpeakingTopic);
	bag.getElement(index).setFee(FeeRequired);


}