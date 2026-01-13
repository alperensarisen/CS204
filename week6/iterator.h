#include <iostream>
#include "linkedList.h"
using namespace std;

class Iterator{
    public:
        Iterator(const LinkedL & list):myList(list),myCurrent(nullptr){}
        //! We used reference parameter for Linked list parameter 
        //! Thus copy constructor will not work and we will work on 
        //! original linked list
        void Init(){
            myCurrent = myList.head;
        }
        bool HasMore() const{
            return (myCurrent != nullptr);
        }
        int current() const{
            return myCurrent->value;
        }
        void next(){
            myCurrent = myCurrent->next;
        }
    private:
        const LinkedL & myList; //! To access the linked list
        //? reference variable, since we dont need to create copy of it
        //? const, since we must do not change anything

        node *myCurrent;  //! to access the next node of the linked list
};