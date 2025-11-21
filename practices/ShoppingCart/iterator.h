#ifndef ITERATOR_H_
#define ITERATOR_H_
#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

class Iterator{
    public:
        Iterator(const cart & l):list(l),mycurrent(nullptr){}
        void Init(){mycurrent = list.head;}
        bool hasMore(){return mycurrent != nullptr;}
        string current(){return mycurrent->data.name;}
        void next(){mycurrent = mycurrent->next;}
    private:
        const cart & list;
        typedef cart::node node;
        node * mycurrent;
};
#endif