#include <iostream>
using namespace std;
struct node
{
    int id;
    node *next;

    node(){}
    node(node* n, int i):next(n),id(i){}
};
node* add2end(node* tail, int id){
    node *nn = new node(nullptr,id);
    tail->next = nn;
    return nn;
}   
void DeleteList(node*& head){
    node* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}
void printLL(node * temp){
    
    while(temp != nullptr){
    cout<<temp->id<<" ";
    temp = temp->next;
    }
    cout<<endl;
}
//! Recursion version of deleting
void DeleteLL(node*& head){
    if(head){
        DeleteLL(head->next);
        delete head;
        head = nullptr;
    }
}
node * AddInOrder(node* head, int newkey){
    node* ptr = head; //loop variable
    if(!head||newkey<head->id){
        node* temp = new node;
        temp->id = newkey;
        temp->next = head;
        return temp;
    }
    //! To chechk node one ahead so we dont pass!
    while(ptr->next && ptr->next->id < newkey){
        ptr = ptr->next;
    }
    // postcondition: new node to be inserted just after the node ptr points
    node* temp = new node; //!node to be inserted
    temp->id = newkey;
    temp->next = ptr->next; //! connect to rest
    ptr->next = temp;
    return head;
}
int main(){
    node *head = new node(nullptr,10);
    node *tail = head;

    tail = add2end(tail,20);
    tail = add2end(tail,30);
    tail = add2end(tail,40);
    tail = add2end(tail,50);
    //! Until there I just created basic Linked List to use.
    printLL(head);
    //DeleteList(head);
    //DeleteLL(head);
    node * p = AddInOrder(head,25);
    printLL(head);
    return 0;
}