//? i will use same example with atomic usage case to make it more understandable.
#include <iostream>
#include <thread>
#include <vector>
//! our new feature
#include <mutex>   
using namespace std;
struct Counter
{
    mutex mutex;
    int value;
    Counter():value(0){}
    void increment(){
        mutex.lock();     //! we are locking this area to prevent any other thread join this step
        value++;           
        mutex.unlock();   //! then we unlocked it to make other thread able to reach this part of code
    }
};
void task(Counter& counter){
    for(int i = 0; i<1000000; i++){
        counter.increment();
    }
}
int main(){
    Counter counter;
    vector<thread> threads;
    for(int i = 0; i < 5; i++){
        threads.push_back(thread(task,ref(counter)));
    }
    for(auto& thread : threads){
        thread.join();
    }
    cout<<counter.value;
    return 0;
}
/*
    try {
    lock_guard<std::mutex> guard(mutex);
    ++value;
    } catch (…) {
    handle the error
    }
!   or we can use like this for automatic lock management
*/
 
