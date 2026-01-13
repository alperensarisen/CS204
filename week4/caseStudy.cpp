#include <iostream>
#include "DynIntStack.h"
using namespace std;

int main(){
    DynIntStack stack;
    char token;
    int rhs, lhs, result;
    cout<< "Please enter postfix expression: ";
    while(cin>>token){
        if(token >= '0' && token <= '9') //! if digit
        {
            stack.push(token - '0');
        }
        else{
            stack.pop(rhs);
            stack.pop(lhs); //! Pop two operands
            //and apply the operations. Result is pushed to the stack.
            if(token == '+')
                stack.push(lhs+rhs);
            else if(token == '-')
                stack.push(lhs-rhs);
            else if(token == '*')
                stack.push(lhs*rhs);
            else if(token == '/')
                stack.push(lhs/rhs);

        }
    }
    stack.pop(result);
    cout<<"Result is: "<< result << endl;
    return 0;
}