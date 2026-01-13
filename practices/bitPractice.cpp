#include <iostream>
#include <bitset>
using namespace std;
int main(){
    int x = 5;
    cout<<"-------- XOR ----------\n";
    cout<<bitset<32>(x)<<endl;  
    cout<<bitset<32>(x^x)<<endl;    //equals to 0
    cout<<bitset<32>(x^0)<<endl;    //not effective
    cout<<bitset<32>(x^-1)<<endl;   //reverse to bits
    cout<<bitset<32>(~x)<<endl;     //reverse to bits
    cout<<"--------- AND & ---------\n";
    cout<<bitset<32>(x)<<endl; 
    cout<<bitset<32>(x&0)<<endl;    // equals to 0
    cout<<bitset<32>(x&-1)<<endl;   // not effective
}