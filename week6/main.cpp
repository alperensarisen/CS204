#include "linkedList.h"
#include "iterator.h"
#include <iostream>
using namespace std;
void printList(const LinkedL & list){
    Iterator itr(list);
    for(itr.Init();itr.HasMore();itr.next()){
        cout<<itr.current()<<"\n";
    }
}
int main(){
    LinkedL ll;
    ll.fill();
    cout<<ll;
    ll.printList(ll);
    printList(ll);
}