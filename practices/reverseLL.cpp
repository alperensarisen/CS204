#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v, ListNode *n):val(v),next(n){}
};
void addNewNode(ListNode *h, int value){
    if(!h) h = new ListNode(value,nullptr);
    while(h->next){
        h = h->next;
    }
    h->next = new ListNode(value,nullptr);
    
}
ListNode* reverse(ListNode *h){
    ListNode *prev = nullptr;
    while(h){
        ListNode *nxt = h->next;
        h->next=prev;
        prev = h;
        h=nxt;
    }
    return prev;
}
void printLL(ListNode *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    ListNode *head = new ListNode(1,nullptr);
    addNewNode(head,2);
    addNewNode(head,3);
    addNewNode(head,4);
    addNewNode(head,5);
    printLL(head);
    
    printLL(reverse(head));
}
