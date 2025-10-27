#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int size){
    StackSize = size;
    StackArr = new int[StackSize];
    top = -1;
}
void Stack::push(int num){
    if(isFull()){
        cout<<"Stack is full!!"<<endl;
        return;
    }
    StackArr[++top] = num;
}
void Stack::pop(int &num){
    if(isEmpty()){
        cout<<"Stack is empty there is not any element to pop"<<endl;
        return;
    }
    num = StackArr[top--];
}

bool Stack::isFull(void){
    return top == StackSize -1;

}

bool Stack::isEmpty(void){
    return top == -1;
}