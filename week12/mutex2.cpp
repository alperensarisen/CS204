#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int sum = 0; 
 
int foo(int val) { 
  int res = 0, i; 
  for(i = 0; i < (1<<30); i++) { 
    res = res + (val * i); 
  } 
  return res; 
} 
mutex mtx;
void bar(int i) { 
    mtx.lock();
  sum = sum + foo(i);
    mtx.unlock();
}
const int num_threads = 4; 
 
int main() { 
  thread t[num_threads]; 
 
  for (int i = 0; i < num_threads; i++) { 
    t[i] = thread(bar, i + 1); 
  } 
 
  for (int i = 0; i < num_threads; i++) { 
    t[i].join(); 
  } 
 
  cout << "Sum is " << sum << endl; 
}