#include <iostream>
using namespace std;
int foo(){
    return 5;
}
int main(){
//! -----LVALUES----
    //? You can put an lvalue to the left of the = operator
    int x, *p, arr[5], y;
    /*
    ? These are lvalues: they can be at the left side of
    ? the "=" operator
    * They have persistent place in memory, you can put
    * something in them, take their address with &
    */
//! ----RVALUES----
    //? Basicaly these are not lvalues so they do not have
    //? persistent place in memory
    2;
    x+y;
    //foo();

    //! x+y = 2;
    //! &(x+y);  Compiler gives an error!!

//? ###################################################
    const int &rx = x;
    //rx++; //! Not Possible since it is a const variable
    int &&rrx = foo();
    rrx++;
    cout<<rrx<<"\n"; 

    

    return 0;

}