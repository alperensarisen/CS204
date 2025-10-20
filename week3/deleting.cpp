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
void DeleteList(node* head){
    node* temp;
    while(head != nullptr){
        temp = head;
        delete head;
        head = temp;
    }
}
void printLL(node * temp){
    while(temp != nullptr){
        cout<<temp->id<<" ";
        temp = temp->next;
    }

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
    DeleteList(head);
    printLL(head);
    return 0;
}