#ifndef Time_hpp
#define Time_hpp

#include <iostream>
using namespace std;

class Time
{

private:
    
    int hours;
    int minutes;
    int seconds;
  
public:
    
    
    Time();
    Time(int, int, int, int);
    Time(const Time&);
    Time& setHours(int);
    Time& setMinutes(int);
    Time& setSeconds(int);
    //Time& setTime(int);
  
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
	int getTimeinSeconds() const;

   
    
    friend ostream& operator << (ostream&, const Time&);
    friend istream& operator >> (istream&, Time&);
    bool operator > (const Time& right);
    bool operator < (const Time& right);
    

};


#endif /* Time_hpp */
