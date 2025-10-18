#include <iostream>
using namespace std;
int main(){
    //!Automatic (ordinary) variables(STACK MEMORY): 
    /*
      -It is stores in stack part of memory.
      -Created automatically when the function (or block { ... }) starts.
      -Destroyed automatically when the block ends.
      -You don’t need to manually manage memory.
    */
   //!Dynamic Variables (Heap Memory)
   /*
      -Variables created using the new keyword.
      -Stored in the heap, a different area of memory.
      -You usually use a pointer to access them.

      int* p = new int[100]; //!This code allocate memory for 100 integer in HEAP
   
   */
    return 0;
}