#include "Time.hpp"
#include <iostream>
#include "MyString.h"
using namespace std;

Time::Time()
{
   
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
  
}
Time::Time( int hours, int minutes, int seconds, int atime)
{
   
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    
}
Time::Time(const Time& aTime)
{
   
    setHours(aTime.getHours());
    setMinutes(aTime.getMinutes());
    setSeconds(aTime.getSeconds());
    
}


Time& Time::setHours(int hours)
{
    this->hours = hours;
    return *this;
}

Time& Time::setMinutes(int minutes)
{
    this->minutes = minutes;
    return *this;
}
Time& Time::setSeconds(int seconds)
{
    this->seconds = seconds;
    return *this;
}


int Time::getHours() const
{
    return this->hours;
}
int Time::getMinutes() const
{
    return this->minutes;
}
int Time::getSeconds()const
{
	return this->seconds;
}
int Time::getTimeinSeconds() const
{
    return this->hours * 3600 + minutes * 60 + seconds;
}


ostream& operator << (ostream& strm, const Time& obj)
{
    
    strm << "Time: " << obj.getHours() << ":" << obj.getMinutes() << ":"<< obj.getSeconds() << endl;
    
    return strm;
}

istream& operator >> (istream& strm, Time& obj)
{
    bool validation = false;
    while(!validation)
    {
       
        cout << "Hours: ";
        strm >> obj.hours;
        
        cout << "Minutes: ";
        strm >> obj.minutes;
        
        cout << "Seconds: ";
        strm >> obj.seconds;
        
        if (obj.minutes < 0 || obj.hours < 0 || obj.seconds < 0)
        {
            validation = false;
            cout << "Invalid time. Try again." << endl;
        }
        else
            validation = true;
    }
    return strm;
}


bool Time::operator > (const Time& right)
{
    bool status;
    if (getTimeinSeconds() > right.getTimeinSeconds())
        status = true;
    else if (getTimeinSeconds() == right.getTimeinSeconds())
        status = true;
    else
        status = false;
    return status;
    
    
}

bool Time::operator < (const Time& right)
{
    bool status;
    if (getTimeinSeconds() < right.getTimeinSeconds())
        status = true;
    else if (getTimeinSeconds() == right.getTimeinSeconds())
        status = true;
    else
        status = false;
    return status;
    
}
