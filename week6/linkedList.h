#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iosfwd>
#include <iostream>
#include <iosfwd>
using namespace std;
struct node
{
    int value;
    node *next;
    node(int v,node* n = nullptr):value(v),next(n){}
};
class LinkedL{
    friend class Iterator;
    private:
        node *head;
        int size;
    public:
        LinkedL();
        LinkedL(const LinkedL& other);  //! Copy constructor
        ~LinkedL();                     //! Destructor
        
        void clear();
        void CopyFrom(const LinkedL &rhs);
        void fill();
        void printList(const LinkedL & list) const;
        LinkedL & operator=(const LinkedL & other);
        friend ostream& operator<<(ostream& out,const LinkedL& list);
};

#endif