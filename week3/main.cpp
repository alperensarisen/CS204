#include <iostream>
#include "linkedlist.h"
using namespace std;
int main(){
    linkedlist list;

    list.addToBeginning(40);
    list.addToBeginning(30);
    list.addToBeginning(20);
    list.addToBeginning(10);
    
    list.pritlist();
    list.deletepoint(30);
    list.pritlist();
    return 0;
}
