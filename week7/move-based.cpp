#include <iostream>
using namespace std;

class MyArray{
    public:
        MyArray(int size);
        ~MyArray();
        MyArray(const MyArray & source);
        MyArray(MyArray && source);
        void swap(MyArray & source);

        int& operator[] (const int n) const;
        MyArray& operator=(const MyArray & source);
        MyArray& operator=(MyArray && MyArray);
    private:
    int sz;
    int *mem;
};
MyArray::MyArray(int s):sz(s), mem(new int[s]){
    cout<<"an object of "<< sz <<" integes is constructed\n";
}
MyArray::~MyArray(){
    delete [] mem;
    cout << "the object with " << sz << " integers is destructed\n";
}
MyArray::MyArray(const MyArray & source):sz(source.sz),mem(new int[sz]){
    cout << "copy constructor is called\n";
    for( int i = 0;i<sz;i++){
        (*this)[i] = source[i];
    }
    cout << "copy constructor is done\n";
}
int& MyArray::operator[] (const int n) const{
    if(n<0 || n >= sz){
        throw out_of_range("The subscript operator caused the exception");
    }
    return mem[n];
}
void MyArray::swap(MyArray & source){
    std::swap(mem,source.mem);
    std::swap(sz,source.sz);
}
MyArray::MyArray(MyArray && source):sz(0),mem(nullptr){
    cout << "move constructor is called\n";
    swap(source);
    cout << "move constructor is done\n";
}
MyArray& MyArray::operator=(const MyArray& source){
    cout << "copy assignment is called\n";
    if(this != &source){
        sz = source.sz;
        delete [] mem;
        mem = new int(sz);
        for(int i = 0; i<sz;i++){
            (*this)[i] = source[i];
        }
    }
    cout << "copy assignment is done\n";
    return *this;
}
MyArray& MyArray::operator=(MyArray && source){
    cout << "move assignment is called\n";
    if(this != &source){
        swap(source);
        delete [] source.mem;
        source.mem = nullptr;
        source.sz = 0;
    }
    cout << "move assignment is done\n";
    return *this;
}
int main(){
    cout << endl << "assignment operator usage " << endl;

    MyArray x1(1);
    MyArray x2(2);
    MyArray x3(3);
    
    cout << "copy assignment " <<endl;
    x2 = x1;		
    cout << "move assignment " << endl;
    x3 = move(x1); 
    return 0;
}