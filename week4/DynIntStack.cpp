#include "DynIntStack.h"
#include <iostream>
using namespace std;
DynIntStack::DynIntStack(){
    top = nullptr;
}
void DynIntStack::push(int num){
    StackNode *newnode;
    newnode = new StackNode;
    newnode->value = num;
//? If there are no nodes in the list
//? make newnode the first node
    if(isEmpty()){
        top = newnode;
        newnode->next = nullptr;
    }
    //? Otherwise, insert newnode before top
    else{
        newnode->next = top;
        top = newnode;
    }
}
void DynIntStack::pop(int &num){
    StackNode *temp;
    if(isEmpty()){
        cout<<"The Stack is empty!\n";
    }
    else//! pop value off top stack
    {
        num = top->value;
        temp = top->next;
        delete top;
        top = temp;
        
    }
}
bool DynIntStack::isEmpty(void){
    bool status;
    if(top==nullptr) status = true;
    else status = false;
    return status;
}