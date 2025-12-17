/*
!   HOW CAN WE DETECT ARITHMETIC OVERFLOW
*   It is not same thing with having carry out in MSB
*   If there is a carry out in MSB, we can say that there is a carry overflow (may or may not be arithmetic)!
&   For signed integers, overflow is detected when the result of an arithmetic operation has a different sign than expected based on the operands’ signs.

!   Detecting overflow - Unsigned integers
*   Let us visualize the overflow case on 4-bit unsigned integers
*   15 = 1111 and if we add 1 to 15, then it will be (1)0000 with carry out
*   and value becomes 0 instead of 16
*/