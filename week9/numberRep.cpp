#include <iostream>
using namespace std;
/*
?  0 0 0 0 0 0 1 1 = 3
?  ...
?  1 1 1 1 1 1 1 1 = 255
!------ SIGN MAGNITUDE ------
    000 = 0
    001 = 1
    011 = 3
?   101 = -1
?   110 = -2
?   111 = -3

! DIFFERENT VERSION -Signed numbers: 1’s 
Number  1’s-complement
+7          0111
+6          0110  
+5          0101
+4          0100
+3          0011
+2          0010
+1          0001
+0          0000
-0          1111
-1          1110
-2          1101
-3          1100          
-4          1011
-5          1010
-6          1001
-7          1000
! DIFFERENT VERSION -Signed numbers: 2’s 
Number       2’s-complement
+7              0111
+6              0110  
+5              0101
+4              0100
+3              0011
+2              0010
+1              0001
0               0000    //? THERE IS ONLY ONE 0
-1              1111
-2              1110
-3              1101
-4              1100          
-5              1011
-6              1010
-7              1001
-8              1000  //! There is onw more negative integer

! ------ Decimal Conversion for Negatives ------
? If 1's complement representation is used:
    *invert all bits (i.e. negate):  10010010 => 01101101
    *Then calculate 01101101 => 1 + 4 + 8 + 32 + 64 = 109, Then
    *10010010 = -109
? If 2's complement representation is used:
    *invert all bits (i.e. negate): 1001 0010 => 0110 1101
    *add 1:                                   => 0110 1110
    *calculate (0110 1110): 1x64 + 1x32 + 1x8 + 1x4 + 1x2 = 110, Then
    *10010010 equals to -110
    ! or instead of this:
      1       0       0      1      0      0     1      0
    -128     64       32     16     8      4     2      1

    Calculate it without changing but last one should be negative:
    Hence: 100100102 = -1x2⁷ + 1x2⁴ + 1x2¹ = -110

    ! use the usual binary to decimal conversion, using at the most 
    ! significant bit the negative for the coefficient

!   ----- Subtraction -----
    0 011 = +3
    1 110 = -2
   +______
    0 001 -> which is correct
!   CHAR:
&   The type char is known to store an ASCII character, but actually it stores a signed one byte integer number 
&   Therange is   -128  . .  127
&   ch = -25;  //valid
&   ch = 135;  //out of range, but not a syntax error. Compiler gives a warning

?   The bit representation of 135 in 32 bits = 11111111  11111111 11111111 10000111
?   But according to 2's complement representation it is equal to -121, thus
?   cout<<ch;  will show -121.

!   UNSIGNED CHAR:
&   unsigned char ch;
&   ch = 200;  //valid; the ASCII character with code 200
&   ch = -25;  //out of range, but not a syntax error. Compiler gives a warning

?   -25 is out of range but can be represented in 2's complement as 11100111 in 
?   binary and the unsigned interpretation of this bit string is 231.

!   A NOTE:
?   Example: 4-bit to 8-bit
*   0010  
*   1010  -> 0000 0010 (both has decimal value 2)-> 1111 1010 (both has decimal value -6 in 2's complement)

!   INT:
?   Visual Studio fixed it to 4 bytes: thus, in CS204 wecan assume that int always uses 4 bytes.
&   Range:
*   32 bits(ourcase): -2^31. . . (2^31)-1 è-2,147,483,648 . . . 2,147,483,647
!   LONG:
?   You can use it long num = 5; or long int num = 5;
?   Range is same with int (32 bits)
!   LONG LONG:
?   Can be defined as long long sum; or long long int sum;
?   Do not use it for codes to be ported to other platforms, it won't work.
&   Range: -2^63 (2^63) - 1
!   SHORT:
?   Can be definde as short sum; or short int sum;
*   Always 2 bytes => 16 bits, then
&   Range: -2^15 (2^15) - 1

!   UNSIGNED INTEGER:
unsigned int myint;
unsigned short cinekop;     // same as unsigned short int cinekop; 
unsigned long lufer;        //same as unsigned long int lufer; 
unsigned long long kofana;  // same as unsigned long long int kofana;

&   In unsigned representation there is no sign bit;  most significant bit is part of the 
&   magnitude. Thus we do not need 2's complement.
*   The ranges become:
?   – 16-bit:    0  to (2^16)-1 (defined in limits.h or climits header file)
?   – 32-bit:    0  to (2^32)-1 (defined in limits.h or climits header file)
?   – 64-bit:    0  to (2^64)-1 (defined in limits.h or climits header file)

*   if we assign negative number to unsigned integer variable what will be happend ?
*   unsigned short num = -25;
*   according to 2's complement rep. it equals to 1111 1111 1110 0111, then it will be calculated
*   as a unsigned integer, thus output will be 65511.
*/

int main(){

}