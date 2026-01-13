#include <iostream>
#include <string>
#include "ClockTime.h"

using namespace std;
ClockTime::ClockTime():myHours(0),myMinutes(0),mySeconds(0){}
ClockTime::ClockTime(int secs, int mins, int hours):mySeconds(secs),myMinutes(mins),myHours(hours){
    normalize();
}
void ClockTime::normalize(){
    myMinutes += mySeconds/60;
    mySeconds %= 60;

    myHours += myMinutes/60;
    myMinutes %=60;
}
int ClockTime::hours() const {return myHours;}
int ClockTime::minutes() const{return myMinutes;}
int ClockTime::seconds() const{return mySeconds;}

bool ClockTime::equals(const ClockTime & c) const {
    return (hours() == c.hours() &&
            minutes() == c.minutes() &&
            seconds() == c.seconds());
}
bool ClockTime::less(const ClockTime& c) const{
    return ( hours() < c.hours() ) ||
 
 ( ( hours() == c.hours() ) && ( ( minutes() < c.minutes() ) ||
 ( ( minutes() == c.minutes() ) && ( seconds() < c.seconds() ) )));

}
//! OVERLOADING OPERATORS
bool ClockTime::operator>=(const ClockTime & rhs) const{
    return !(less(rhs));
}

bool ClockTime::operator>=(const int &rhs) const{
    return(hours() >= rhs);
}
bool operator>=(const int & lhs, const ClockTime & rhs){
    ClockTime temp(0,0,lhs);
    return temp>=rhs;
}

const ClockTime & ClockTime::operator+=(const ClockTime & ct){
    mySeconds += ct.mySeconds;
    myMinutes += ct.myMinutes;
    myHours += ct.myHours;
    normalize();

    return *this;
}
ClockTime operator +  (int lhs, const ClockTime& rhs)
{
    ClockTime temp (rhs.mySeconds, rhs.myMinutes, rhs.myHours + lhs);
    return temp;
}
ClockTime operator+ (const ClockTime&rhs, const ClockTime&lhs){
    ClockTime result(lhs);
	result += rhs;
    return result;
}