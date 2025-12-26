//! ----- PROCESS -----
//  Has a self-contained execution environment: code and data
//  Has a complete, private set of basic run-time resources
//  Has its own (virtual) memory space.

//  not (always) implies a full application
//*    But each application has at least one process

//  can work with other processes either via cooperation or independently
//*     The processes can communicate with each other with Inter-Process Communication (IPC) techniques
//*     Processes may be running on one or more computers connected by a network.

//The OS shares the run-time resources among the processes in a secure way.
//! ----- THREAD -----
/*
&   Aprocessor does not execute processes but threads

&   A thread…
        is a “path of execution” in a process
        is a single sequential flow of control within a program
        is usually considered as a light-weight process
            Both process and threads provide an execution environment
            But threads are much cheaper

&   exists within a process
        Every process has at least one (usually the main thread)
        The resources of the process are shared among its threads (including memory and files)

&   can work simultaneously with other threads

! Threads only contain ony necessary information, such as a stack (for local variables, function arguments, return values)

?   The main reason is achieving concurrency
*       A typical application has many tasks
            The real computation and data processing
            Interacting with the user via a Graphical User Interface (GUI)
*       Communication between threads is very fast
*/
#include <iostream>
#include <thread>
using namespace std;
void hello(){
    cout<<"Hello Thread\n";
}
int main(){
    thread aThread(&hello);
    aThread.join();
    cout<<"Bye main\n";
    return 0;
}