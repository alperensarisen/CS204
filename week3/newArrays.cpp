#include <iostream>
using namespace std;
int main(){
//! 1D arrays with new operator
//! To dynamically allocate an array, specify the array size in
//! square brackets [] after the type:
    typedef int *ptrInt;
    ptrInt p;
    p = new int[20];    //? dynamically allocate enough
    delete [] p;        //? memory for an array of 20 ints.
    return 0;
}