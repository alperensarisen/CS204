#ifndef STACK_H_
#define STACK_H_
#include <iostream>

using namespace std;
class Stack {
    private:
        int* StackArr;
        int StackSize;
        int top;
    public:
    Stack(int size);

    void push(int value);
    void pop(int &);
    bool isFull(void);
    bool isEmpty(void);
};
#endif