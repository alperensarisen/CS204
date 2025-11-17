#include <iostream>
#include "ClockTime.h"
using namespace std;

int main()
{
    int h,m,s;
    cout << "enter two sets of 'h m s' data " << endl
         << "Enter non integers to terminate program." << endl << endl;

    cin >> h >> m >> s;
    ClockTime a(s,m,h);
    cout<<a.hours()<<":"<<a.minutes()<<":"<<a.seconds()<<endl;
    return 0;
}