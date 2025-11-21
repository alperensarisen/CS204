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
cart& cart::operator=(const cart &rhs){
    if(this == &rhs){
        clear();
        copyFrom(rhs);
    }
    return *this;
}
cart& cart::operator+=(const product &rhs){
    if(!head){
        head = new node(rhs,nullptr);
        size++;
        return *this;
    }
    node *p = head;
    while(p->next){
        p=p->next;
    }
    p->next = new node(rhs,nullptr);
    size++;
    return *this;
}
cart cart::operator+(const cart rhs) const{
    cart result(*this);
    node *p = rhs.head;
    while(p){
        result += p->data;
        p = p->next;
    }
    return result;
}
bool cart::operator==(const cart & rhs) const{
    node *p1 = head;
    node *p2 = rhs.head;
    while(p1&&p2){
        if(p1->data.name != p2->data.name || p1->data.weigh != p2->data.weigh) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
int cart::getSize()const{
    return size;
}
ostream& operator<<(ostream &out, const cart& list){
    cart::node *p = list.head;
    while(p){
        out<<"Name of product: "<<p->data.name<<", Weigh of product: "<<p->data.weigh<<endl;
        p = p->next;
    }
    return out;
}