#include <iostream>
using namespace std;
//! Argument Count(int argc):
//* Number of argument the program takes.
//! Argument Vector(char **argv):
//* Pointers which hold each arguments
int main(int argc, char **argv){
    if(argc<3){
        cout<<"You did not write the file name!\n";
        return 1;
    }
    cout<<"The file will be opened: "<<argv[1]<<endl;
    cout<<"The file will be opened: "<<argv[2]<<endl;
    cout<<"####################################\n";
    for(int i = 0; i<argc; i++){
        cout<<"argv["<<i<<"] = "<<argv[i]<<endl;
    }
//? This is useful sometimes for example with fstream 
//? we can take the filename "./app sample1.txt",
//? then filename will be able to use.
    return 0;
}
