#include "linkedlist.h"
using namespace std;
linkedlist::linkedlist(){
    head = nullptr;
}
void linkedlist::addToBeginning (int n){
    node *ptr = new node(n,head);
    head = ptr;
}
void linkedlist::pritlist(){
    node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
node *linkedlist::deletepoint(int deleted){
    node *temp = head;
    node *dlt;
    if(head->data == deleted){
        dlt = head;
        head = head->next;
        delete dlt;
        return head;
    }
    while(temp->next != nullptr && temp->next->data != deleted){
        temp = temp->next;
    }
    dlt = temp->next;
    
    temp->next = dlt->next;
    delete dlt;
    return head;
}