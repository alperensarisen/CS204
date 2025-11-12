#include <iostream>
#include "IntQueue.h"
using namespace std;

int main(){
    IntQueue que(4);
    que.enqueue(5);
    que.enqueue(10);
    que.enqueue(15);
    que.enqueue(20);
    que.print();
    return 0;
}