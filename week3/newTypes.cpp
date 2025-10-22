#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;

    node();
    node(int d, node *n):data(d),next(n){}
};
struct doublyLL
{
//!   Each node does not only keep a  
//!   pointer for the next node, but also for 
//!   the previous node.

    int data;
    doublyLL *next;
    doublyLL *prev;
    doublyLL(){}
};

void printLL(node *temp){
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node* add2end(node *head, node *tail, int key){
    node *nn = new node(key,head);
    //! The tail linked to head so this is a circular list
    tail->next = nn;
    return nn;
}
int countCircular(node *origin){
    if(!origin){
        return 0; //! list is empty
    }
    int count = 0;
    node *ptr = origin;
    do{
        count++;
        ptr = ptr->next;
    } while (ptr != origin); 
    //! Loop until you reach where started.
    return count;
}
int main(){
    //!CIRCULAR LIST
    //?Last node does not point to nullptr, 
    //?but points to the first node.
    //*There is no head or tail.
    node *head = new node(1,nullptr);
    node* tail = head;

    tail = add2end(head, tail, 2);
    tail = add2end(head, tail, 4);
    tail = add2end(head, tail, 5);
    printLL(head);
    return 0;
}