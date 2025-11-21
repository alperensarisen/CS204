#include <iostream>
using namespace std;
const int MAX = 3;
int main(){
    int var[MAX] = {10,100,200};
    int *ptr;
    ptr = var; //* it means ptr = &var[0]
    //* Therefore ptr is pointing address of first element of var

    for(int i = 0; i<MAX; i++){
        cout<<"Address of "<<var[i]<<" is: "<<ptr<<endl;
        ptr++;
    }
    cout << "*********************\n";
    int* ptr1 = &(var[0]);
    int* ptr2 = &(var[2]);
    cout<<ptr1<<" "<<ptr2<<endl;
    cout<<(ptr2-ptr1) * sizeof(int)<<endl;  //! int allocates 4 byte
    cout<< "**********************\n";
    char* cp = (char*)&var[0];
    cout<<"Bytes of first element:\n";
    for(int i = 0; i<4; i++){
        cout<<int(*cp+i)<<endl;
    }
    return 0;
}