#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
    Node(){}
    Node(int i, Node* n):info(i),next(n){}
};
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList &other); //copy ctor
        LinkedList(LinkedList && other);     //move ctor

        void clear();
        virtual void add(int);
        virtual void get(int);

    protected:
        Node *head;
};
LinkedList::LinkedList():head(nullptr){}
LinkedList::~LinkedList(){clear();}
LinkedList::LinkedList(const LinkedList& other){
    
    if(other.head == nullptr) return;
    

    Node *other_temp = other.head;

    head = new Node(other_temp->info,nullptr);
    other_temp = other_temp->next;

    Node *temp = head;
    while(other_temp){
        temp->next = new Node(other_temp->info,nullptr);
        temp = temp->next;
        other_temp = other_temp->next;
    }

}
LinkedList::LinkedList(LinkedList && other){
    head = other.head;
    other.head = nullptr;
    #ifdef _DEBUG
        cout<<"Move constructor called.\n";
    #endif
}
void LinkedList::clear(){
    if(!head){
        throw "LinkedList is already empty!";
    }
    Node *temp = head;
    while(temp){
        Node *tbd = temp;
        temp = temp -> next;
        delete tbd;
    }
}
void LinkedList::add(int v){
    if(!head){
        head = new Node(v,nullptr);
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(v,nullptr);
}
void LinkedList::get(int a){
    if(head->info == a){
        Node* tbd = head;
        head = head->next;
        delete tbd;
        return;
    }
    Node *temp = head;
    while(temp && temp->next){
        Node *tbd = nullptr;
        if(temp->next->info == a){
            tbd = temp->next;
            temp->next = tbd->next;
            delete tbd;
        }
        
        temp = temp->next;
    }
}