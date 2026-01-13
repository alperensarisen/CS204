#include <iostream>
#include "DynQueue.h"
using namespace std;

int main(){
    DynQueue que;
    que.enqueue(5);
    que.enqueue(10);
    que.enqueue(15);
    que.enqueue(20);
    que.print();
    int value;
    que.dequeue(value);
    que.print();
    que.dequeue(value);
    que.print();

}