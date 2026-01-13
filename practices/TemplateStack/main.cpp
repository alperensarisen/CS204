#include <iostream>
#include <string>
#include <iosfwd>
using namespace std;
template <class itemType>
struct node{
    itemType value;
    node<itemType> *next;
    node<itemType>(itemType v, node<itemType> *n):value(v),next(n){}
};

template <class itemType>
class Stack{
    private:
        node<itemType> *head;
        int size;
    public:
        Stack();        
        Stack(const Stack<itemType> & other);  //? copy constructor!
        ~Stack();
        void add(itemType n);
        void pop();
        void copyFrom(const Stack<itemType> & other);
        itemType & top() const;
        bool isEmpty() const;
        int getSize() const;
        void clear();
        void printList() const;
        Stack<itemType> & operator =(const Stack<itemType> & rhs);
        Stack<itemType> & operator+=(const Stack<itemType> & rhs);
        bool operator==(const Stack<itemType> & rhs) const;
        
};
template<class itemType>
Stack<itemType>::Stack():head(nullptr),size(0){}
template<class itemType>
Stack<itemType>::Stack(const Stack<itemType> & other){copyFrom(other);}
template<class itemType>
Stack<itemType>::~Stack(){clear();}
template<class itemType>
void Stack<itemType>::add(itemType n){
    if(!head){
        head = new node<itemType>(n,nullptr);
        size++;
        return;
    }
    node<itemType> *nh = new node(n,head);
    head = nh;
    size++;
}
template<class itemType>
void Stack<itemType>::pop(){
    if(!head){
        throw out_of_range("Stack is empty!");
    }
    node<itemType> *p = head;
    head = head->next;
    delete p;
    size--;
}
template<class itemType>
void Stack<itemType>::copyFrom(const Stack<itemType> & other){
    head = nullptr;
    size = 0;
    if(!other.head) return;
    head = new node<itemType>(other.head->value,nullptr);
    size = 1;

    node<itemType> *nh = head;
    node<itemType> *p = other.head->next;
    while(p){
        nh->next = new node<itemType>(p->value,nullptr);
        nh = nh->next;
        p = p->next;
        size++;
    }
}
template<class itemType>
itemType & Stack<itemType>::top() const{
    if(!head){
        throw out_of_range("Stack is empty!");
    }
    return head->value;
}
template<class itemType>
bool Stack<itemType>::isEmpty() const{
    return !head;
}
template<class itemType>
int Stack<itemType>::getSize() const{ return size;}
template<class itemType>
void Stack<itemType>::clear(){
    node<itemType> *p = head;
    node<itemType> *dlt = p;
    while(p){
        p = p->next;
        delete dlt;
        dlt = p;
    }
    size = 0;
}
template<class itemType>
void Stack<itemType>::printList() const{
    if(!head){
        cout<<"Empty Stack! p:\n";
        return;
    }
    node<itemType> *temp = head;
    while(temp){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
template<class itemType>
Stack<itemType> & Stack<itemType>::operator=(const Stack<itemType> & rhs){
    if(this == &rhs) return *this;
    clear();
    copyFrom(rhs);
    return *this;
}
template<class itemType>
Stack<itemType> & Stack<itemType>::operator+=(const Stack<itemType> & rhs){
    if(!head){
        *this = rhs;
        return *this;
    }
    node<itemType> *p = rhs.head;
    while(p){
        add(p->value);
        p=p->next;
        //! size++; add function already increasing the size!!
    }
    return *this;
}
template<class itemType>
bool Stack<itemType>::operator==(const Stack<itemType> & rhs) const{
    node<itemType> *p1 = head;
    node<itemType> *p2 = rhs.head;
    while(p1&&p2){
        if(p1->value != p2->value) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main() {
    // ===== INT STACK =====
    Stack<int> s;

    s.add(10);
    s.add(20);
    s.add(30);

    cout << "Int stack size: " << s.getSize() << "\n";
    cout << "Top: " << s.top() << "\n";   // 30

    s.pop();
    cout << "Top after pop: " << s.top() << "\n"; // 20

    // Hepsini boşalt
    s.clear();
    cout << "Is int stack empty? " << (s.isEmpty() ? "YES" : "NO") << "\n\n";

    // ===== STRING STACK =====
    Stack<string> st;
    st.add("Jack");
    st.add("Ronny");
    st.add("Jahson");

    cout << "String stack size: " << st.getSize() << "\n";
    cout << "Top: " << st.top() << "\n";   // Jahson

    st.pop();
    cout << "Top after pop: " << st.top() << "\n";   // Ronny

    st.clear();
    cout << "After clear, empty? " << (st.isEmpty() ? "YES" : "NO") << "\n";

    cout << "\n====== END OF TEST ======\n";

    Stack<string> stringStack;
    stringStack.add("hello");
    stringStack.add("cpp");
    stringStack.add("world");
    cout<<"LIST 1: \n";
    stringStack.printList();
    Stack<string> stringStack2;
    stringStack2 = stringStack;
    cout<<"LIST 2:\n";
    cout<<"== operator test:\n";
    if(stringStack == stringStack2){
        cout<<"equal\n";
    }
    else cout<<"not equal\n";
    cout<<"Check of += operator: \n";
    Stack<string> stck;
    stck.add("a");
    stck.add("b");
    stck.add("c");
    stringStack.printList();
    stringStack += stck;
    stringStack.printList();
    cout<<stringStack.getSize();
    
    
    return 0;
}
