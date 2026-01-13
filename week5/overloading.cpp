#include <iostream>
using namespace std;
/*This code demonstrates function overloading in C++. There are two max functions: one takes int parameters, 
the other takes double parameters. In main(), the compiler chooses the appropriate version based on the argument types: max(5,6) 
calls the int version, and max(8,7) calls the double version. */
int max(int a , int b){
    if(a>b) return a;
    else return b;
}
double max(double a, double b){
    if(a>b) return a;
    else return b;
}
int main(){
    int i = max(5,6);
    double d = max(8,7);
    return 0;
}