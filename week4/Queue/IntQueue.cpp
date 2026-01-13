#include "IntQueue.h"
#include <iostream>
using namespace std;

IntQueue::IntQueue(int s){
    queueArray = new int[s];
    queueSize = s;
    front = 0;  //-1
    rear = -1;
    numItems = 0;
    #ifdef _DEBUG
        cout << "A queue with "<<s<< " elements created\n";
    #endif
}
void IntQueue::enqueue(int num){
    if(isFull()){
        cout<<"Queue is full. "<< num << " not enqueued!\n";
    }
    else{
        //! calculate the new rearest position cicularly
        rear = (rear + 1)%queueSize;
        queueArray[rear] = num;
        numItems++;
        #ifdef _DEBUG
            cout<<num<< " enqueued\n";
        #endif
    }
}

void IntQueue::dequeue(int &num){
    if(isEmpty()){
        cout << "Attempting to dequeue on empty queue, exiting program...\n";
        exit(1);
    }
    else{
        //move front
        front = (front + 1) % queueSize;
        num = queueArray[front];
        numItems--;
    }
}
bool IntQueue::isEmpty() const {
    if(numItems > 0) return false;
    else return true;
}
bool IntQueue::isFull() const {
    if(numItems < queueSize) return false;
    else return true;
}
void IntQueue::clear(){
    front = -1;
    rear = -1;
    numItems = 0;
    #ifdef _DEBUG
        cout<<"queue cleared\n";
    #endif
}
void IntQueue::print() const{
    if(isEmpty()){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"Queue elements: ";
    int index = front;
    for (int i = 0; i<numItems; i++){
        cout<< queueArray[index]<< " ";
        index = (index+1)%queueSize;
    }
    cout<<endl;
}