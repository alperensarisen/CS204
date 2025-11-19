#include <iostream>
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
        Stack();        //TODO: copy constructor!
        ~Stack();
        void add(itemType n);
        void pop();
        itemType & top() const;
        bool isEmpty() const;
        int getSize() const;
        void clear();
};
template<class itemType>
Stack<itemType>::Stack():head(nullptr),size(0){}
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
int main() {
    cout << "====== STACK TEST ======\n\n";

    // ----------------------------
    // 1) INT STACK TEST
    // ----------------------------
    cout << "INT STACK TEST\n";

    Stack<int> s;

    cout << "Is empty? " << (s.isEmpty() ? "YES" : "NO") << endl;

    cout << "Adding 10, 20, 30...\n";
    s.add(10);
    s.add(20);
    s.add(30);

    cout << "Size: " << s.getSize() << endl;
    cout << "Top: " << s.top() << endl;      // Expected: 30

    cout << "Pop...\n";
    s.pop();
    cout << "New top: " << s.top() << endl;  // Expected: 20
    cout << "Size: " << s.getSize() << endl;

    // ----------------------------
    // 2) POP UNTIL EMPTY
    // ----------------------------
    cout << "\nPOP ALL ELEMENTS:\n";
    while(!s.isEmpty()){
        cout << "Popping: " << s.top() << endl;
        s.pop();
    }

    cout << "Is empty now? " << (s.isEmpty() ? "YES" : "NO") << endl;

    // ----------------------------
    // 3) POP FROM EMPTY STACK (Exception)
    // ----------------------------
    cout << "\nTEST EXCEPTION ON POP (EXPECTED)\n";
    try {
        s.pop();
    }
    catch (exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // ----------------------------
    // 4) STRING STACK TEST
    // ----------------------------
    cout << "\nSTRING STACK TEST\n";

    Stack<string> st;
    st.add("Gamze");
    st.add("Ablam");
    st.add("Canim");

    cout << "Size: " << st.getSize() << endl;
    cout << "Top: " << st.top() << endl;     // Canim

    st.pop();
    cout << "Top after one pop: " << st.top() << endl;   // Ablam

    // ----------------------------
    // 5) CLEAR TEST
    // ----------------------------
    cout << "\nCLEAR TEST\n";
    
    st.clear();
    cout << "After clear, size = " << st.getSize() << endl;
    cout << "Is empty? " << (st.isEmpty() ? "YES" : "NO") << endl;

    cout << "\n====== END OF TEST ======\n";
    return 0;
}
