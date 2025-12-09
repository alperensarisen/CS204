#include <iostream>
#include <string>
using namespace std;
template <class itemType>
struct node
{
    itemType data;
    node *next;

    node(){}
    node(const itemType & v, node *n):data(v),next(n){}
};
template <class itemType>
class linkedList{
    private:
        node<itemType> *head;
        int size;
    public:
        linkedList();
        linkedList(const linkedList & other); // Copy constructor
        ~linkedList();                        // ~Deconstructor

        void printList() const;
        void addToBeginning(itemType nd);
        void deleteList();
        void copyFrom(const linkedList & other);
};
template <class itemType>
linkedList<itemType>::linkedList():head(nullptr),size(0){}
template <class itemType>
linkedList<itemType>::linkedList(const linkedList & other){
    copyFrom(other);
}
template <class itemType>
linkedList<itemType>::~linkedList(){
    deleteList();
}
template <class itemType>
void linkedList<itemType>::printList() const{
    if(!head){
        cout<<"List is empty!\n";
        return;
    }
    node<itemType>* temp = head;
    while(temp){
        cout<<temp->data<<" | ";
        temp = temp->next;
    }
    cout<<endl;
}
template <class itemType>
void linkedList<itemType>::addToBeginning(itemType nd){
    if(!head){
        head = new node<itemType>(nd,nullptr);
        size = 1;
        return;
    }
    node<itemType> *nh = new node(nd,head);
    size++;
    head = nh;
}
template <class itemType>
void linkedList<itemType>::deleteList(){
    if(!head) return;
    node<itemType>* temp = head;
    node<itemType>* tbd;
    while(temp){
        tbd = temp;
        temp = temp->next;
        delete tbd;
    }
    size = 0;
    head = nullptr;
}
template <class itemType>
void linkedList<itemType>::copyFrom(const linkedList & other){
    deleteList();
    if(!other.head){
        head = nullptr;
        size = 0;
        return;
    }
    
    head = new node(other.head->data,nullptr);
    size = 1;
    node<itemType> *temp2 = head;
    node<itemType> *temp = other.head->next;
    while(temp){
        temp2->next = new node<itemType>(temp->data,nullptr);
        size++;
        temp2 = temp2->next;
        temp = temp->next;   
    }   
}
int main(){
    string tmnt[] = {"Leonardo", "Donatello",  "Michelangelo ", "Raphael"};
    linkedList<int> intList;
    linkedList<string> strList;

    for(int i = 0; i<4; i++){
        strList.addToBeginning(tmnt[i]);
        intList.addToBeginning(i+1);
    }

    intList.printList();
    strList.printList();
}