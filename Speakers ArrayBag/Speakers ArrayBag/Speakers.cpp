#include "Speakers.h"
#include <iostream>
#include <string>
using namespace std;

Speakers::Speakers()
{
	Name = " ";
	TelephoneNumber = " ";
	SpeakingTopic = " ";
	FeeRequired = 0;
}

Speakers::Speakers(string aName, int aPhone, string aSpeaking, double aFee)
{
	this->Name = aName;
	this->TelephoneNumber = aPhone;
	this->SpeakingTopic = aSpeaking;
	this->FeeRequired = aFee;
}

Speakers::~Speakers()
{
}

void Speakers::setName(string aName)
{
	this->Name = aName;
}

void Speakers::setPhone(string aPhone)
{
	this->TelephoneNumber = aPhone;
}

void Speakers::setSpeaking(string aSpeaking)
{
	this->SpeakingTopic = aSpeaking;
	cout << SpeakingTopic << endl;
}

void Speakers::setFee(double aFee)
{
	if (FeeRequired < 0)
	{
		cout << "No se aceptan números negativos\n";

	}
	else
	{

		this->FeeRequired = aFee;
	}
}

string Speakers::getName()const
{
	return Name;
}

string Speakers::getPhone()const
{
	return TelephoneNumber;
}

string Speakers::getSpeaking()const
{
	return  SpeakingTopic;
}

double Speakers::getFee()const
{
	return FeeRequired;
}

void Speakers::display() const
{
	cout << "El nombre es: " << Name << endl;
	cout << "El # de telefono es: " << TelephoneNumber << endl;
	cout << "El SpeakingTopic es: " << SpeakingTopic << endl;
	cout << "La cuota es: " << FeeRequired << endl;
}

bool Speakers::operator == (const Speakers& obj)const
{
	return (Name == obj.Name && TelephoneNumber == obj.TelephoneNumber && SpeakingTopic == obj.SpeakingTopic && FeeRequired == obj.FeeRequired);
}