#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Event.h"

class Customer
{
private:
	string name;	// name of customer
	char type;	//	type of event: arrive, sign in, renew license, renew registration, and cope with the cashier. 
	int time;	//	arrival time in seconds
	char pay;	//	type of payment:  $  for cash,  C  for check
	char choice;

public:
	Customer();
	Customer(string, char, int, char, char);
	Customer(const Event&);
	~Customer();
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

	Customer operator =(const Customer&);
	Customer operator =(const Event& right);
	bool operator ==(const Customer&)const;
	bool operator !=(const Customer&)const;
	bool operator <(const Customer&)const;
	bool operator >(const Customer&)const;
};

Customer::Customer() : name(""), time(0), type(' '), pay(' '), choice(' ')
{

}
Customer::Customer(string name, char type, int time, char pay, char choice)
{
	this->name = name;
	this->type = type;
	this->time = time;
	this->pay = pay;
	this->choice = choice;
}

Customer::Customer(const Event& obj)
{
	this->name = obj.getName();
	this->type = obj.getType();
	this->time = obj.getTime();
	this->pay = obj.getPay();
	this->choice = obj.getChoice();
}

Customer::~Customer()
{

}
void Customer::setName(string in)
{
	name = in;
}
void Customer::setType(char in)
{
	type = in;
}
void Customer::setTime(int in)
{
	time = in;
}
void Customer::setPay(char in)
{
	pay = in;
}
void Customer::setChoice(char in)
{
	choice = in;
}
string Customer::getName() const
{
	return name;
}
char Customer::getType() const
{
	return type;
}
int Customer::getTime() const
{
	return time;
}
char Customer::getChoice() const
{
	return choice;
}
//int Customer::getLength() const
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
///*	
//	Sign in 10 seconds
//	Renew license 90 seconds
//	Register automobile 60 seconds
//
//	See cashier(payment) 30 seconds
//	See cashier(check not approved) 10 seconds
//*/
//}
char Customer::getPay() const
{
	return pay;
}
Customer Customer::operator =(const Customer& right)
{
	type = right.type;
	time = right.time;
	name = right.name;
	pay = right.pay;
	choice = right.choice;

	return *this;
}
Customer Customer::operator =(const Event& right)
{
	type = right.getType();
	name = right.getName();
	time = right.getTime();
	pay = right.getPay();
	choice = right.getChoice();

	return *this;
}

bool Customer::operator ==(const Customer& right)const
{
	return name[0] == right.getName()[0];
}
bool Customer::operator !=(const Customer& right)const
{
	return name[0] != right.getName()[0];
}
bool Customer::operator <(const Customer& right)const
{
	return name[0] < right.getName()[0];
}
bool Customer::operator >(const Customer& right)const
{
	return name[0] > right.getName()[0];
}