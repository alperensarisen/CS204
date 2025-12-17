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

!   UNSIGNED CHAR:
&   unsigned char ch;
&   ch = 200;  //valid; the ASCII character with code 200
&   ch = -25;  //out of range, but not a syntax error. Compiler gives a warning

?   -25 is out of range but can be represented in 2's complement as 11100111 in 
?   binary and the unsigned interpretation of this bit string is 231.
*/
int main(){

}