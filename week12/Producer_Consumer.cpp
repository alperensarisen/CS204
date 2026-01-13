#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class MyBuffer{
    public:
        mutex mtx;
        MyBuffer(int s):size(s),number_of_items(0),elements(new int[size]){}

        int remove(int consumer_id){
            mtx.lock();
            while(number_of_items == 0) {
                mtx.unlock();
                mtx.lock();
            }
            int item = elements[--number_of_items];
            cout<< item << ": "<<consumer_id<< " : "<<number_of_items<<endl;
            mtx.unlock();
            return item;
        }

        void insert(int item){
            mtx.lock();
            while(number_of_items == size){
                mtx.unlock();
                mtx.lock();
            }
            elements[number_of_items++] = item;
            cout<<item<<": "<<number_of_items<<endl;
            mtx.unlock();
        }
    private:
        int size;
        int *elements;
        int number_of_items;
};
class Producer{
    public:
        Producer(int i, MyBuffer &br):id(i),b(br){}
        void operator()(){
            for(int i = 0; i<10; i++){
                b.insert(id);
            }
        }
    private:
        int id;
        MyBuffer &b;
};
class Consumer{
    public:
        Consumer(int i, MyBuffer &br):id(i),b(br){}
        void operator()(){
            for(int i = 0;i<1;i++){
                int val = b.remove(id);
            }
        }
    private:
        int id;
        MyBuffer &b;
};
int main(){
    MyBuffer buf(3);
    
    thread producers[1];
    thread consumers[10];
    for(int i = 0; i<10 ; i++){
        consumers[i] = thread((Consumer(i,ref(buf))));
    }
    for(int i = 0; i < 1; i++) {
        producers[i] = thread((Producer(i, ref(buf))));
    }
    for(int i = 0; i < 10; i++) {
        consumers[i].join();
    }
    for(int i = 0; i < 1; i++) {
        producers[i].join();
    }
//! WORK ON IT ???????