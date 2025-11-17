#ifndef MESSAGELIST_H_
#define MESSAGELIST_H_
#include "Message.h"
#include <iosfwd>
class MessageList{
    private:

        struct node
        {
            message msg;                                //! This struct objects will hold message objects
            node *next;
            node(message m, node*n = nullptr):msg(m),next(n){};   //! Constructor with parameter
        };

        node *head;
        int size;
        void clear();                               //! to clear linkedlist
        void CopyFrom(const MessageList &other);    //! helper of deep copy 
    public:
        MessageList();                            //! Default constructor
        MessageList(const MessageList& other);    //! copy constructor
        ~MessageList();                           //! Destructor

        MessageList & operator+=(const message & other);    //! Add new message end of the list
        MessageList & operator=(const MessageList & rhs);       //! Assigment
        MessageList operator+(const MessageList & ml) const ;   //! Merge two list

        bool operator==(const MessageList & rhs) const;         //! Check equality of two list

        int getSize() const {return size;}
        friend ostream& operator<<(ostream& out, const MessageList& ml);
};
#endif