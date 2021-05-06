#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
	string name;	// name of Event
	char type;	//	type of event: arrive, sign in, renew license, renew registration, and cope with the cashier. 
	int time;	//	arrival time in seconds
	char pay;	//	type of payment:  $  for cash,  C  for check
	char choice;
public:
	Event();
	Event(string name, char type, int time, char pay, char);
	~Event();
	Event(const Event& obj);
	void setName(string in);
	void setType(char in);
	void setTime(int in);
	void setPay(char in);
	void setChoice(char in);
	string getName() const;
	char getType() const;
	int getTime() const;
	char getChoice() const;
	//int getLength() const;
	char getPay() const;

	Event operator = (const Event&);
	bool operator ==(const Event& right)const;
	bool operator !=(const Event& right)const;
	bool operator <(const Event& right)const;
	bool operator >(const Event& right)const;
};

Event::Event() : name(""), time(0), type(' '), pay(' '), choice(' ')
{
}
Event::Event(string name, char type, int time, char pay, char choice)
{
	this->name = name;
	this->type = type;
	this->time = time;
	this->pay = pay;
	this->choice = choice;
}

Event::Event(const Event& obj)
{
	this->name = obj.getName();
	this->type = obj.getType();
	this->time = obj.getTime();
	this->pay = obj.getPay();
	this->choice = obj.getChoice();
}

Event::~Event()
{

}
void Event::setName(string in)
{
	name = in;
}
void Event::setType(char in)
{
	type = in;
}
void Event::setTime(int in)
{
	time = in;
}
void Event::setPay(char in)
{
	pay = in;
}
void Event::setChoice(char in)
{
	choice = in;
}
string Event::getName() const
{
	return name;
}
char Event::getType() const
{
	return type;
}
int Event::getTime() const
{
	return time;
}
char Event::getChoice() const
{
	return choice;
}
//int Event::getLength() const
//{
//	if (type == 'S')
//		return 10;
//	else if (type == 'L')
//		return 90;
//	else if (type == 'R')
//		return 60;
//	else if (type == 'P')
//	{
//		if (pay == '$')
//			return 30;
//		else
//			return 10;
//	}
//	else
//		return 0;
//
//	/*
//		Sign in 10 seconds
//		Renew license 90 seconds
//		Register automobile 60 seconds
//		See cashier(payment) 30 seconds
//		See cashier(check not approved) 10 seconds
//	*/
//}
char Event::getPay() const
{
	return pay;
}
Event Event::operator = (const Event& right)
{
	type = right.getType();
	name = right.getName();
	time = right.getTime();
	pay = right.getPay();
	choice = right.getChoice();
	return *this;
}
bool Event::operator ==(const Event& right)const
{
	return time == right.getTime();
}
bool Event::operator !=(const Event& right)const
{
	return time != right.getTime();
}
bool Event::operator <(const Event& right)const
{
	return time < right.getTime();
}
bool Event::operator >(const Event& right)const
{
	return time > right.getTime();
}