#include <iostream>
#include <string>
using namespace std;

template <class opType>
class Add{
    public:
        Add(opType op1, opType op2);
        opType operand(int i);
        opType result();
    private:
        opType op1,op2;
};
template <class opType>
Add<opType>::Add(opType f, opType s):op1(f),op2(s){}
template <class opType>
opType Add<opType>::operand(int i){
    if(i==1) return op1;
    else return op2;
}
template <class opType>
opType Add<opType>::result(){
    return op1+op2;
}
int main(){
    Add<int> a(5, 12);
    cout << a.operand(1) << " + " << a.operand(2) 
    << " = " << a.result() << endl;
    Add<string> b("cs", "204");
    cout << b.operand(1) << " + " << b.operand(2) 
    << " = " << b.result() << endl;
    Add<char> c('2', '3');
    cout << c.operand(1) << " + " << c.operand(2) 
    << " = " << c.result() << endl;
    return 0;
}