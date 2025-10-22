#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
    node(int d, node* n):data(d),next(n){}
};
class linkedlist{
    private:
        node *head;
    public:
        linkedlist();
        void pritlist();
        void addToBeginning(int n);
        node *deletepoint(int deleted);
};