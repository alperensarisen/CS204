#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic> // to prevent race condition
using namespace std;
/*void hello(){
    //chrono::seconds dura(2);
    //this_thread::sleep_for(dura);
    cout<<"Hello thread\n";
}
int main(){
    thread athread(&hello);
    athread.detach();
    cout<<"Bye main\n";
    if(athread.joinable()){cout<<"athread is joinable\n";}
    else cout<<"athread is not joinable\n";
    return 0;
}*/
/*void pause_thread(int n){
    this_thread::sleep_for(chrono::seconds(n));
    cout<<"thread "<<n<<" joined\n";
}
int main(){
    cout<<"Spawning 2 threads...\n";
    thread t1(pause_thread,1);  //function, parameter 1, parameter 2, ...
    thread t2(pause_thread,2);
    cout<<"Done spawning threads.\n";
    cout<<"Now waiting for them to join...\n";
    t1.join();
    t2.join();
    cout<<"All threads joined\n";
    return 0;
}*/
struct Counter{
    atomic<int> value;          //! if it is regular int variable you will get different values
    Counter():value(0){}        //! atomic makes it thread-safe 
    void increment(){value++;}

};
void task(Counter &counter){
    for(int i = 0; i < 100000; i++){
        counter.increment();
    }
}
int main(){
    Counter counter;
    vector<thread> threads;
    for(int i = 0; i<5; i++){
        threads.push_back(thread(task,ref(counter)));
    }
    for(auto& thread: threads){
        thread.join();
    }
    cout<<counter.value<<endl;
    return 0;
}