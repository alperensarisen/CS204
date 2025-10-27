#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack s(5);  //! Stack with 5 element.
    int value;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop(value);
    cout<<"The value that is popped: "<<value<<endl;

    s.pop(value);
    cout<<"The value that is popped: "<<value<<endl;

    s.pop(value);
    cout<<"The value that is popped: "<<value<<endl;


    //! Try to pop from empty stack
    s.pop(value);

    return 0;
}