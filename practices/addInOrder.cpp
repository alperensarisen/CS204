#include <iostream>
using namespace std;
struct node{
    int value;
    node *next;
    node():value(0),next(nullptr){}
    node(int v,node* n):value(v),next(n){}
};

node* addInOrder(node* _head, int vl){
   if(!_head) return new node(vl,nullptr);
   if(_head->value > vl) return new node(vl,_head);
    
   node* temp = _head;
    while(temp->next && temp->next->value  < vl){
        temp = temp->next;
    }
    temp->next = new node(vl,temp->next);
    return _head;
}

void printList(node* head){
    node* p = head;
    while(p){
        cout<<p->value<<" ";
        p = p->next;
    }
}
int main(){
    node* head = nullptr;          // boş başlayalım, daha temiz
    head = addInOrder(head,3);
    head = addInOrder(head,5);
    head = addInOrder(head,2);
    head = addInOrder(head,6);
    head = addInOrder(head,1);
    printList(head);

}