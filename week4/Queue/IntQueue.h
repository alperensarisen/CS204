//! STATİC QUEUE
#ifndef INTQUEUE_H_
#define INTQUEUE_H_
class IntQueue{
    private:
        int *queueArray;        //! We are using array becasuse this is statick queue
        int queueSize;          //! Capacity of queue
        int front;
        int rear;   
        int numItems;           //! # of elements currently in queue 
    public:
        IntQueue(int);          //! Constructor, parameter is capacity
        void enqueue(int);
        void dequeue(int &);
        bool isEmpty() const;
        bool isFull() const;
        void clear();           //! clear all elements in the queue 
        void print() const;
    };
#endif