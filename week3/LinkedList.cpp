#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(){}
    node(int d, node * n):data(d),next(n){}
    //!Constructor with 2 parameter.
};
node* Add2End(node *tail,int id){
    node *nn = new node(id,nullptr);
    tail->next = nn;
    return nn;
    //?This added the new id to the end of the list, 
    //?but now tail also needs updating – how?
    //?we could return the new tail from the function: 
    //?node *Add2End(node * tail, int id) 
    //?and let the caller do the update
    //?or we could make tail a reference parameter and update it here…
    //?but we left it as it is right now
}
int main(){
    node *head = new node(10,nullptr);
    node *tail = head;

    tail = Add2End(tail,20);
    tail = Add2End(tail,30);
    tail = Add2End(tail,40);
    node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}