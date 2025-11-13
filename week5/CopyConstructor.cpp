#include <iostream>
using namespace std;
struct A
{
    private:
        int val;
    public:
        A(){val = 0;};
        A(int a):val(a){};
        A(const A &other){                                  //! Copy constructor
            cout << "Copy Constructor called!" << endl;
            val = other.val;
        };
        int getValue(){return val;}
};
struct node{
    int value;
    node *next;
    node(int v, node *n){
        value = v;
        next = n;
    }
};
class LinkedList{
    private:
        node *head;
        int size;
    public:
        LinkedList();
        LinkedList(const LinkedList&);
        ~LinkedList();
        void printlist() const;
        void addToBeginning(int n);
        node *create_clone() const;
};
LinkedList::LinkedList(){
    head = nullptr;
    size = 0;
}
LinkedList::LinkedList(const LinkedList& copy){
    head = copy.create_clone();
    size = copy.size;
}
LinkedList::~LinkedList(){
    cout<<"Deleting...\n";
}
void LinkedList::printlist() const{
    node *temp = head;
    while(temp){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void LinkedList::addToBeginning(int val){
    node *n = new node(val,head);
    head = n;
    size++;
}
node* LinkedList::create_clone() const{
    if(head == nullptr) return nullptr; //* if list is empty, clone is empty as well
    node *cloneHead = new node(head->value,nullptr);
    node *ptr = head->next;
    node *ptrClone = cloneHead;

    while(ptr){
        ptrClone->next = new node(ptr->value,nullptr);
        ptr = ptr->next;
        ptrClone = ptrClone->next;
    }
    return cloneHead;
}
int main(){
    LinkedList list1;
    list1.addToBeginning(1);  
    list1.addToBeginning(2);  
    list1.addToBeginning(3);  
    list1.printlist();
    LinkedList list2;
    list2 = list1;
    list2.printlist();


    /*A a(3);
    A b = a;
    cout<<a.getValue()<<endl;
    cout<<b.getValue()<<endl;*/

    return 0;
}