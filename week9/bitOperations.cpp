#include <iostream>
#include <bitset>       //to print bit
using namespace std;
/*
! ASCII table 256 different code (0-255)
?   & bitwise and
?   | bitwise or
?   ^ bitwise exclusive or
?   ~ Complement(unary operator, takes only one operand)
?   << shift left
?   >> shift right

! Do not confuse with && ||
*/
int main(){
    char x,y,z,n;
//* Bitwise and ( & )
    x = 0xd5;   //?     1 1 0 1 0 1 0 1
                //!     ⬇ ⬇ ⬇ ⬇ ⬇ ⬇ ⬇ ⬇   
    y = 0x6c;   //?     0 1 1 0 1 1 0 0
    z = x&y;    //*     0 1 0 0 0 1 0 0

//* Bitwise or ( | )
    n = x|y;
    cout<<x<<" "<<y<<" "<<z<<" "<<n<<endl;

//* Bitwise XOR ( ^ )
    char c1, c2, c3;
    c1 = 0x45;
    c2 = 0x71;
    c3 = c1 ^ c2;
    cout<<c1<<" "<<c2<<" "<<c3<<endl;

//* Bitwise Complement ( ~ )
//* Complement operation (~) converts bits with value 0 to 1 and bits with value 1 to 0.

//! The result of ! ,  && and || operations is an integral data type with the 
//! value 0 (every bit is a zero) or 1 (LeastSignificant bit is 1, all the others are 0).

//! ------- SHIFT OPERATOR --------
//? << means shifting left:

    char ch2 = 0x59;
    cout<<bitset<8>(ch2)<<endl;
    ch2 = ch2 << 3;
    cout<<bitset<8>(ch2)<<endl;
    cout<<endl;
//? >> means shifting right

    char ch3 = 0x32;
    cout<<bitset<8>(ch3)<<endl;
    ch3 = ch3 >> 2;
    cout<<bitset<8>(ch3)<<endl;
}