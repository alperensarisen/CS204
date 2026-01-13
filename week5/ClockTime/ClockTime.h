#ifndef CLOCKTIME_H_
#define CLOCKTIME_H_
#include <string>
using namespace std;
class ClockTime{
    public:
        ClockTime();
        ClockTime(int sec, int mins, int hours); //! CONSTRUCTORS

        int hours() const;
        int minutes() const;
        int seconds() const;
        //string tostring() const;  //* converts to string

        bool equals(const ClockTime& ct) const;
        bool less(const ClockTime& ct) const;

        const ClockTime & operator+=(const ClockTime&ct);
        bool operator>=(const ClockTime&rhs) const;
        bool operator>=(const int &rhs) const;
        friend ClockTime operator+(int lhs, const ClockTime& rhs);
        
        //! friend functions are not a member of class but we are giving a 
        //! special permission to reach the private values by using friende key word.
        private:
            void normalize();
            int mySeconds;
            int myMinutes;
            int myHours;
};
ClockTime operator+(const ClockTime & rhs, const ClockTime &lsh);
#endif