#include <iostream>
#include "Cart.h"

using namespace std;

cart::cart():size(0),head(nullptr){}
cart::cart(const cart& other){copyFrom(other);}
cart::~cart(){clear();}

void cart::clear(){
    if(!head) return;
    node* ptr = head;
    
    while(ptr){
        node *nxt = ptr->next;
        delete ptr;
        ptr = nxt;
    }
    size = 0;
    head = nullptr;
}
void cart::copyFrom(const cart& other){
    clear();
    if(!other.head){return;}
    head = new node(other.head->data,nullptr);
    size = 1;
    node *p = other.head->next;
    node *nh = head; 
    while (p)
    {
        nh->next = new node(p->data,nullptr);
        nh = nh->next;
        size++;
        p = p->next;
    }
    
}