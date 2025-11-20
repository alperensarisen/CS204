#include<iostream>
#include<string>

using namespace std;
void printReverse(){
    string word;
    if(cin>>word){
        printReverse();
        cout<<word<<" \n";
    }
}
int power(int x, int y){
    if(y == 0){return 1;}
    return x*power(x,y-1);
}
int factorial(int x){
    if(x == 0) return 1;
    return x * factorial(x-1);
}
int fib(int x){
    if(x == 1) return 1;
    if(x== 0) return 0;
    return fib(x-1) + fib(x-2);
}
int main(){
    //printReverse();
    cout<<power(2,5)<<endl;
    cout<<factorial(3)<<endl;
    cout<<fib(4);
    return 0;
}