#pragma once
#include <iostream>
using namespace std;

class Event
{
private:
	int pages;	//	type of event: arrive, sign in, renew license, renew registration, and cope with the cashier. 
	int time;	//	arrival time in seconds
	int length;
	char type;	// type of event A for assigned, P for printed
	int printerNum;
public:
	Event();
	Event(char, int, int, int);
	~Event();
	Event(const Event& obj);
	void setTime(int in);
	//void setPages(int in);
	void setType(char in);
	int getTime() const;
	int getPages() const;
	int getLength() const;
	char getType() const;
	int getPrinterNum() const;

	Event operator = (const Event&);
	bool operator ==(const Event& right)const;
	bool operator !=(const Event& right)const;
	bool operator <(const Event& right)const;
	bool operator >(const Event& right)const;
};

Event::Event() : pages(0), time(0), type(' '), length(0), printerNum(0)
{
}
Event::Event(char type, int pages, int time, int printerNum)
{
	this->time = time;
	this->pages = pages;
	this->type = type;
	this->printerNum = printerNum;

	if(printerNum == 1)
		length = int(double(pages) / (10.0 / 60.0));
	else if (printerNum == 2)
	{
		if (pages <= 10)
			length = int(double(pages) / (10.0 / 60.0));
		else
			length = int(double(pages) / (20.0 / 60.0));
	}
	else
	{
		if (pages <= 10)
			length = int(double(pages) / (10.0 / 60.0));
		else if (pages <= 20)
			length = int(double(pages) / (20.0 / 60.0));
		else
			length = int(double(pages) / (30.0 / 60.0));
	}
}

Event::Event(const Event& obj)
{
	this->time = obj.time;
	this->pages = obj.pages;
	this->length = obj.length;
	this->type = obj.type;
	this->printerNum = obj.printerNum;
}

Event::~Event()
{

}
void Event::setTime(int in)
{
	time = in;
}
//void Event::setPages(int in)
//{
//	pages = in;
//	if (pages <= 10)
//		length = int(double(pages) / (10.0 / 60.0));
//	else if (pages <= 20)
//		length = int(double(pages) / (5.0 / 60.0));
//	else
//		length = int(double(pages) / (3.33 / 60.0));
//}
void Event::setType(char in)
{
	type = in;
}
int Event::getPages() const
{
	return pages;
}
int Event::getTime() const
{
	return time;
}
int Event::getLength() const
{
	return length;
}
char Event::getType() const
{
	return type;
}
int Event::getPrinterNum() const
{
	return printerNum;
}
Event Event::operator = (const Event& obj)
{
	this->time = obj.time;
	this->pages = obj.pages;
	this->length = obj.length;
	this->type = obj.type;
	this->printerNum = obj.printerNum;
	return *this;
}
bool Event::operator ==(const Event& right)const
{
	return (time == right.getTime());
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