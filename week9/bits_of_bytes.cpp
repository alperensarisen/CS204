#include <iostream>
#include <bitset>

using namespace std;
int main(){
    const char IO_ERROR = 0x01;         //? 0000 0001
    const char CHANNEL_DOWN = 0x10;     //? 0001 0000
    char flags = 0;                     //? 0000 0000

    flags = flags | CHANNEL_DOWN;

    if(IO_ERROR & flags != 0){              //! Check 1st bit
        cout<<"I/O error flag is set\n";
    }
    else if(flags & CHANNEL_DOWN != 0 ){    //! Check 5th bit
        cout<<"Channel down error flag is set\n";
    }

    flags = flags & ~IO_ERROR;              // clear the ERROR flag
    cout<<bitset<8>(flags)<<endl;


}