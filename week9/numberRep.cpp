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
*/
int main(){

}