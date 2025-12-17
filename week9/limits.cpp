#include <climits>  //? Or #include <limits.h>
#include <bitset>   //? to print bit representation of
#include <iostream>
using namespace std;
int main(){
    unsigned short usnum = 3000;
    cout<< (short) usnum << endl;
    cout<< bitset<16>((short) usnum) << endl;
//! As we see from output MSB is 0 (0000 1011 1011 1000)
    unsigned short usnum2 = 63000;
    cout << (short) usnum2<<endl; 
    cout<< bitset<16>((short) usnum2) << endl;
//! As we see from output MSB is 1 (1111011000011000)
    unsigned int a = 5;
    int b = -10;
    if (a+b < 0)
        cout << "hede" << endl;
    else
        cout << "hodo" << endl;
    return 0;
//* We expected to see hede in output but it was hodo, since if expression contains
//* an unsigned value, signed value will be converted to unsigned.
}
