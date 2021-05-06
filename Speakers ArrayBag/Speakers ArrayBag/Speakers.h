#pragma once


#include <iostream>
#include <string>
using namespace std;

class Speakers
{
private:
	string Name;
	string TelephoneNumber;
	string SpeakingTopic;
	double FeeRequired;

public:

	Speakers();
	Speakers(string, int, string, double);
	~Speakers();
	void setName(string);
	void setPhone(string);
	void setSpeaking(string);
	void setFee(double);
	string getName() const;
	string getPhone() const;
	string getSpeaking() const;
	double getFee() const;
	void display() const;
	bool operator == (const Speakers& obj)const;

};