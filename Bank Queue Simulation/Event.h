#pragma once
#include <iostream>
using namespace std;

class Event
{
private:
	char type;
	int time;	//	in seconds
	int length;	//	length of transaction

public:
	Event();
	Event(char, int, int);
	~Event();
	void setType(char in);
	void setTime(char in);
	void setLength(char in);
	char getType() const;
	int getTime() const;
	int getLength() const;
	Event operator = (const Event&);
	bool operator ==(const Event& right)const;
	bool operator !=(const Event& right)const;
	bool operator <(const Event& right)const;
	bool operator >(const Event& right)const;
};

Event::Event() : time(0), type(' '), length(0)
{
}
Event::Event(char type, int time, int length)
{
	this->type = type;
	this->time = time;
	this->length = length;
}

Event::~Event()
{

}
void Event::setType(char in)
{
	type = in;
}
void Event::setTime(char in)
{
	time = in;
}
void Event::setLength(char in)
{
	length = in;
}
char Event::getType() const
{
	return type;
}
int Event::getTime() const
{
	return time;
}
int Event::getLength() const
{
	return length;
}
Event Event::operator = (const Event& obj)
{
	type = obj.type;
	time = obj.time;
	length = obj.length;
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