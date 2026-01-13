#include <iostream>
#include <bitset>
using namespace std;
/*
!   HOW CAN WE DETECT ARITHMETIC OVERFLOW
*   It is not same thing with having carry out in MSB
*   If there is a carry out in MSB, we can say that there is a carry overflow (may or may not be arithmetic)!
&   For signed integers, overflow is detected when the result of an arithmetic operation has a different sign than expected based on the operands’ signs.

!   Detecting overflow - Unsigned integers
*   Let us visualize the overflow case on 4-bit unsigned integers
*   15 = 1111 and if we add 1 to 15, then it will be (1)0000 with carry out
*   and value becomes 0 instead of 16

!   BIT OPERATIONS ON SIGNED/UNSIGNED NUMBERS:
*   works same except right shift. The sign become important in this case.
*   works with both unsigned and 2's complement numbers.

*   shift left by one means x2, shift left by three means x8   
?   a << 5 (multiply by 2^5)

!   SHIFTIN RIGHT:
*   it works different for signed and unsigned numbers.
&   For unsigned numbers:
?       -Drop rightmost k bits
?       -append k zeros to the left

&   For signed numbers
?       -drop rightmost k bits
?       -append the sign bit k times to the left
?       -called arithmetic shift


*   Shifting one to right means divide 2
*   Shifting n to right means divide 2^n.

!   SUMMARY for Bit Shifting as Multiplication & Division:
– Multiplies or divides by corresponding power of 2.
?   – a << 5    (multiply by 2^5)
?   – a >> 5    (divide by 2^5)

!NOTE: Remember, when you need to use only positive numbers to manipulate bits, use unsigned numbers
.
or you need
*/
int main(){
    int a = 19;
//! Shift left by one means multplication by 2.
    a = a << 1;
    cout<<bitset<8>(a)<<endl;
    cout<<a<<endl;


    cout<<"---- shifting right ----\n";
//! For positive:
    char c = 8;
    cout<<"Before shift: "<<bitset<8>(c)<<endl;
    c = c >> 2;
    cout<<"After shift:  "<<bitset<8>(c)<<endl;
    cout<<"c becomes: "<<(int)c<<endl<<endl;
    
//! For negative:
    char c1 = -8;
    cout<<"Before shift: "<<bitset<8>(c1)<<endl;
    c1 = c1 >> 2;
    cout<<"After shift:  "<<bitset<8>(c1)<<endl;
    cout<<"c1 becomes: "<<(int)c1<<endl<<endl;

//! For unsigned
    unsigned char c2 = 0xf8;     //1111 1000 = 248
    cout<<"Before shift: "<<bitset<8>(c2)<<endl;
    c2 = c2 >> 2;
    cout<<"After shift:  "<<bitset<8>(c2)<<endl;
    cout<<"c2 becomes: "<<(int)c2<<endl<<endl;
    return 0;
}