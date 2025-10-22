#include <iostream>
#include "linkedlist.h"
using namespace std;
int main(){
    linkedlist list;
    //!TYPEDEF
    typedef int* IntPtr;
    int a = 10;
    IntPtr p = &a;
//! Avoids mistake of forgetting the  * character
//! Also you can use reference parameters instead of pointer
//! void swap (int & x, int & y)
//! void swap (int * x, int * y)
//! both of them are able to used.
    list.addToBeginning(40);
    list.addToBeginning(30);
    list.addToBeginning(20);
    list.addToBeginning(10);
    
    list.pritlist();
    list.deletepoint(30);
    list.pritlist();
    return 0;
}
