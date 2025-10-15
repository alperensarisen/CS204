#include <iostream>
using namespace std;
void opperate(int a, int b, int (*ptr) (int,int)){
    cout<<"Result is: "<<ptr(a,b)<<endl;
}
int add(int a, int b){return a+b;}
int multp(int a, int b){return a*b;}
int f1(int a){return 5;}
int main(){
    //? Functions are also in stored memory.
    
    double f2(char, char);
    int (*pf)(int) = f1; //! is a valid statement but you can also use &f1
    //!int (*pf) (int) = f2; will not be a valid.
    //! First, the return types are not same (int and char)
    //! Second, the number of parameters is not same
    opperate(3,4,add);
    opperate(3,4,multp);
    return 0;
}