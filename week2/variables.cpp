//!– Local variables are declared in a block.
//!– Global variables are declared outside of all blocks
#include <iostream>
using namespace std;
int e_var = 20;
void myFunction() {
    static int count = 0;
    count++;
    cout << "Count: " << count <<endl;
}
int main(){
    cout<<"The main file: "<<e_var<<endl;
    myFunction(); //it shows 1
    myFunction(); //it shows 2
    myFunction(); //it shows 3
    //! Even though the function runs multiple times, count does not reset — it remembers its previous value.
    return 0;
}