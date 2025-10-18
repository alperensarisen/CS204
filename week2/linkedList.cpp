    //! LINKED LIST
    //? dynamic memory allocation
    //? insertion/deletion is cheap (no shifting)
    //? more cumbersome to program with
#include <iostream>
#include <string>
using namespace std;
struct node {
    //string word;
    //int num;
    
    int data;
    node *next;  /* pointer for the next node */ 
    
    //default constructor
    node(){}
    //constructor
    //node(string w, int n):word(w),num(n){}
};
int main(){
    node *head = new node();
    node* second = new node();
    node* third = new node();
    node* fourth = new node();
    
    head->data=10;
    head->next = second;
    
    second->data=20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = nullptr;

    node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //! [10] -> [20] -> [30] -> NULL
    return 0;
}