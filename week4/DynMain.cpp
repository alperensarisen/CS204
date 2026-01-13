#include <iostream>
#include "DynIntStack.h"
using namespace std;
int main(){
    DynIntStack stack;
    int chatchVar;

    //Push the values 5,10,15
    for(int i = 0; i<=15;i+=5){
        cout<<"Push: " << i << endl;
        stack.push(i);
    }
    cout<<endl;

    //Pop three value then attempt one more.

    for(int j = 1; j <= 3; j++){
        cout<<"Pop: ";
        stack.pop(chatchVar);
        cout<<chatchVar<<endl;
    }
    cout<<"\nAttempting to pop again...";
    stack.pop(chatchVar);
    return 0;
}