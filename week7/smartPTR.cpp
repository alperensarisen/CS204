#include <iostream>
#include <string>
#include <memory>
using namespace std;
//! Smart pointer prevent memory leaks if you forget to delete it
class MyClass{
    public:
        MyClass(){cout<<"My class constructed\n";}
        ~MyClass(){cout<<"My class destructed\n";}
        void do_something(){cout<<"\tSomething is done\n";}
};
int main(){
    unique_ptr<int> ptr_1 = make_unique<int>(15);
    cout<<"*ptr_1: "<<*ptr_1<<endl;

    unique_ptr<string> ptr_2 = make_unique<string>();
    cout<<"*ptr_2: "<<*ptr_2<<endl;
    *ptr_2+="hello";
    cout<<"*ptr_2: "<<*ptr_2<<endl;
    unique_ptr<MyClass> ptr = make_unique<MyClass>();
//? unique_ptr<MyClass> other_ptr = make_unique<*ptr>();
//! this is not possible since unique pointers are not able to be copied.
    ptr->do_something();
//& Smart Pointers: shared_ptr
    shared_ptr<MyClass> shr_ptr = make_shared<MyClass>();
    shared_ptr<MyClass> shr_ptr2 = make_shared<MyClass>(*shr_ptr);
    // in this case we are using shared pointer so shr_ptr is able to be copied.
    shr_ptr->do_something();
}