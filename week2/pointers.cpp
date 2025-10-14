#include <iostream>
using namespace std;
int main(){
    //Pointer is a variable type shuch as int douoble etc.
    //but it stores address in computer memory
    //The purose:
    //  Basis for implementing linked data structures linked lists, trees, graphs...
    //  Provide dynamic memory allocation, variable size arrays

    int myNum = 12;
    int *ptr = &myNum;
    // & symbol is for take the address in the memory
    cout<<ptr<<endl;  //it is address of myNum
    cout<<*ptr<<endl; //by dereference we can get the value which is 12
    // A pointer is defined as: type *pointer_variable_name;
    //char *ptr = nullptr this is a char pointer but we dont know where pointers points.
    //because it is null variable
    double c = 5;
    double *ctr = &c; //we assigned an address to pointer
    //therefore we can learn the value of pointer by doing
    cout<<"The address of char c is: "<<(ctr)<<endl;
    double *qtr;
    qtr = ctr;
    cout<<qtr<<endl;
    //Now qtr and ctr are pointing the same address.
    //a pointer uses 4 bytes of memory when you have 32-bit adresses
    //a pointer uses 8 bytes of memory when you have 64-bit adresses
    *ctr = 6;
    cout<<"The new value of c is "<<*ctr<<endl;
    //by dereferencing we can also change to value in the address.


    //Dynamic memory allocation with 'new'
    double *p;       //This pointer for double type but it points nowhere right now.
    p = new double; //Memory is allocated to store a double value
    cout<<p<<endl;
    return 0;
}