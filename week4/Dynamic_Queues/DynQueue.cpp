#include <iostream>
#include "DynQueue.h"
using namespace std;

DynQueue::DynQueue(){
    front = nullptr;
    rear = nullptr;
    #ifdef _DEBUG
        cout<<"An empty queue has been created\n";
    #endif
}
void DynQueue::enqueue(int num){
    if(isEmpty()){
        front = new QueueNode(num);
        rear = front;
    }
    else{
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
    #ifdef _DEBUG
        cout << num << " enqueued\n";
    #endif
}
void DynQueue::dequeue(int &num){
    QueueNode *temp;
    if(isEmpty()){
        cout << "Attempting to dequeue on empty queue, exiting program...\n";
        exit(1);
    }
    else{
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}
bool DynQueue::isEmpty() const{
    if(front == nullptr) return true;
    else return false;
}
void DynQueue::clear(){
    int value;
    while(!isEmpty())
        dequeue(value);
    #ifdef _DEBUG
        cout << "queue cleared\n";
    #endif
}
void DynQueue::print(){
    QueueNode *temp;
    if(isEmpty()){
        cout<<"EMPTY!\n";
    }
    else{
        temp = front;
        cout<<"Elemets of queue: ";
        while(temp){
            cout<<temp->value<< " ";
            temp = temp->next;
        }
        cout<<endl;
    }
}