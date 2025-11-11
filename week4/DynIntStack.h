#ifndef DYNINTSTACK_H_
#define DYNINTSTACK_H_
//! We were using array in static stacks insted of linkedlist.
struct StackNode
{
    int value;
    StackNode *next;
};
class DynIntStack{
    private:
        StackNode *top;
    public:
        DynIntStack(void);
        void push(int);
        void pop(int &);
        bool isEmpty(void);
};



#endif