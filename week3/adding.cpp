#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;

    node(){}
    node(int d, node *n):data(d),next(n){}
};
node* add2end(node *tail, int d){
    node* nn = new node();
    nn->data = d;
    nn->next = nullptr;
    
    tail->next = nn;
    return nn;
}
void printLL(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
node* addInOrder(node* head, int newkey){
    node* ptr = head; //? Loop variable
    //? In the if statement we are checking the head
    //? If head is bigger than the value that we want to add
    //? We can directly add to beggining
    if(!head || newkey < head->data){
        return new node(newkey,head);
    }

    node* prev; //? This is for to point previous node
    //? In the while loop we are trying to find that previous point
    while(ptr && ptr->data < newkey){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new node(newkey,ptr);
    return head;
}
node* AddInOrderRecursive(node* head, int newkey){
    node* ptr = head;
    if(!head || head->data > newkey){
        return new node(newkey,head);
    }

    head->next = AddInOrderRecursive(head->next,newkey);
    return head;
}
int main(){
    node* head = new node();
    head->data = 10;
    head->next = nullptr;

    node *tail = head;
    tail = add2end(tail,20);
    tail = add2end(tail,30);
    tail = add2end(tail,40);
    tail = add2end(tail,50);
    printLL(head);
    //! Until here I just created
    node* n = addInOrder(head,25);
    cout<<endl;
    printLL(head);
    node* f = addInOrder(head,45);
    cout<<endl;
    printLL(head);
   return 0; 
}