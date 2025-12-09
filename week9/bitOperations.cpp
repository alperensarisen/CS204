#include <iostream>
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
    x = 0xd5;   //?     1 1 0 1 0 1 0 1
                //!     ⬇ ⬇ ⬇ ⬇ ⬇ ⬇ ⬇ ⬇   
    y = 0x6c;   //?     0 1 1 0 1 1 0 0
    z = x&y;    //*     0 1 0 0 0 1 0 0

    n = x|y;
    cout<<x<<" "<<y<<" "<<z<<" "<<n<<endl;

    char c1, c2, c3;
    c1 = 0x45;
    c2 = 0x71;
    c3 = c1 ^ c2;
    cout<<c1<<" "<<c2<<" "<<c3<<endl;
}