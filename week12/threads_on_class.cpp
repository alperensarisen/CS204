//! Threads can work on any callable object
//! if the class overloads the () operator, its objects are callable
#include <iostream>
#include <thread>
using namespace std;
class Task{
    public:
    void operator()(int a){
        cout<<"operator()"<<" parameter a = "<<a<<endl;
        foo();
        bar();
    }
    private:
        void foo(){cout<<"hoy\n";}
        void bar(){cout<<"hey\n";}
};
int main(){
    Task tsk;
    thread t(tsk, 10);
    t.join();
    return 0;
}