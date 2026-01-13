#include <iostream>
using namespace std;
int counter(){
    static int var = 0;
    return var++;
}
int main(){
    cout<<counter()<<" ";
    cout<<counter()<<" ";
    cout<<counter()<<" ";
    cout<<counter()<<" ";
    cout<<counter()<<" ";
    return 0;
}