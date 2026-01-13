#include <iostream>

using namespace std;
template<class itemType>
struct node{
    itemType info;
    node *next;

    node(const itemType & s, node *n):info(s),next(n){}
};
template<class itemType>
class LinkedList{
    private:
        node<itemType> *head;
        int size;
    public:
        LinkedList();
        LinkedList(const LinkedList & other);
        ~LinkedList();
        void printList() const;
        void addToBeginning(itemType n);
        void deleteList();
        node<itemType> *createClone() const; 

};
//! CONSTRUCTOR
template<class itemType>
LinkedList<itemType>::LinkedList(){
    head = nullptr;
    size = 0;
}

//! COPY CONSTRUCTOR
template<class itemType>
LinkedList<itemType>::LinkedList(const LinkedList<itemType> & other){
    head = other.createClone();
    size = other.size;
}

//! DESTRUCTOR
template<class itemType>
LinkedList<itemType>::~LinkedList(){
    node<itemType> *ptr = head;
    while(ptr){
        node<itemType> *temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}
template<class itemType>
void LinkedList<itemType>::addToBeginning(itemType n){
    node<itemType> *ptr = new node<itemType>(n,head);
    head = ptr;
    size++;
}
template<class itemType>
node<itemType> *LinkedList<itemType>::createClone() const{
    if(head == nullptr) return nullptr;
    node<itemType> *headClone = new node<itemType>(head->info,nullptr);
    node<itemType> *ptr = head->next; //? second node in original list
    node<itemType> *ptrClone = headClone;
    while(ptr){
        ptrClone->next = new node<itemType>(ptr->info,nullptr);
        ptr = ptr->next;
        ptrClone = ptrClone->next;
    }
    return headClone;
}
template <class itemType>
void LinkedList<itemType>::printList() const{
    node<itemType> *p = head;
    while(p){
        cout<<p->info<<" ";
        p = p->next;
    }
    cout<<"\n";
}
int main()
{
    string tmnt[] = {"Leonardo", "Donatello",  "Michelangelo ", "Raphael"};
    LinkedList<string> strlist; //Linked list object with string element type
    LinkedList<int> intlist;
    //Linked list object with integer element type
    for (int k=0; k < 4; k++)  
    {
        strlist.addToBeginning(tmnt[k]);
        intlist.addToBeginning(k+1);
    }
    cout << "string list contains:\n";
    strlist.printList();
    cout << "integer list contains:\n";
    intlist.printList();
} 