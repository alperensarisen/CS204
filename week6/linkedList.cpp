#include <iostream>
#include "linkedList.h"
#include "iterator.h"
using namespace std;

LinkedL::LinkedL():head(nullptr),size(0){};
LinkedL::LinkedL(const LinkedL & other):head(nullptr),size(0){CopyFrom(other);}
LinkedL::~LinkedL(){clear();}

void LinkedL::clear(){
    node* temp = head;
    while(temp){
        node *next = temp->next; 
        delete temp;
        temp = next;
    }
    size = 0;
    head = nullptr;
}
void LinkedL::CopyFrom(const LinkedL & other){
    head = nullptr;
    size = 0;
    if(!other.head) return;

    head = new node(other.head->value,nullptr);
    size++;
    node *cur = head;
    node *N = other.head->next;

    while(N){
        cur->next = new node(N->value,nullptr);
        cur = cur->next;
        N = N->next;
        size++;
    }
}
LinkedL & LinkedL::operator=(const LinkedL & other){
    if(this == &other)
        return *this;

    clear();
    CopyFrom(other);
    return *this;
}
void LinkedL::fill(){
    int arr[5] = {1,2,3,4,5};
    head = new node(arr[0],nullptr);
    node *temp = head;
    for(int i = 1; i<5; i++){
        temp->next = new node(arr[i],nullptr);
        temp = temp->next;
    }
}
ostream& operator<<(ostream & out, const LinkedL & list){
    node* p = list.head;
    if(!p){
        return out<<"List is empty :p \n";
    }
    int index = 1;
    while(p){
        out<<"["<<index<<".] "<<"Element: "<<p->value<<"\n";
        p = p->next;
        index++;
    }
    return out;
}
void LinkedL::printList(const LinkedL & list) const{
    Iterator iter(list);
    for (iter.Init(); iter.HasMore(); iter.next()){
        cout << iter.current() << endl;
    }
}