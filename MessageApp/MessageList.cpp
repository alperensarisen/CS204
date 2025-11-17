#include <iostream>
#include "MessageList.h"

using namespace std;

void MessageList::clear(){
    node *p = head;
    while(p){
        node *temp = p->next;
        delete p;
        p = temp;
    }
    head = nullptr;
    size = 0;
}

void MessageList::CopyFrom(const MessageList& other){
    head = nullptr;
    size = 0;

    node *p = other.head;
    while(p){
        *this += p->msg;
        p = p->next;
    }
}
MessageList::MessageList():head(nullptr),size(0){}
MessageList::MessageList(const MessageList& other):head(nullptr),size(0){CopyFrom(other);}
MessageList::~MessageList(){clear();}

//! Assignment operator
MessageList & MessageList::operator=(const MessageList& other){
    if(this != &other){
        clear();
        CopyFrom(other);
    }
    return *this;
}
//! Operator += : Add message end of the list
MessageList & MessageList::operator+=(const message& msg){
    node* n= new node(msg);
    if(head == nullptr){
        head = n;
    }
    else{
        node *p = head;
        while(p->next){     //* to find the last node
            p=p->next;
        }
        p->next = n;       //* Adding a new node to end
    }
    size++;
    return *this;
}
//! Operator+ = merge two list and return a new one
MessageList MessageList::operator+(const MessageList& rhs) const{
    MessageList result(*this);
    node* p = rhs.head;
    while(p){
        result += p->msg;       //! add new elements to end
        p=p->next;
    }
    return result;
}
//! Operator == : Comparison the equality
bool MessageList::operator==(const MessageList& rhs) const{
    if(size != rhs.size) return false;
    node *p1 = head;
    node* p2 =rhs.head;
    while(p1&&p2){
        if(p1->msg.msg != p2->msg.msg || p1->msg.sender != p2->msg.sender)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
//! Operator << : to print list to terminal
ostream& operator<<(ostream& out, const MessageList& ml){
    MessageList::node* p = ml.head;
    int index = 0;
    while(p){
        out<<"["<<index<<"] "<<p->msg.sender<<": "<<p->msg.msg<<endl;
        p = p->next;
        index++;
    }
    return out;
}