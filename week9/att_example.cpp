#include <iostream>
#include <bitset>
using namespace std;
/*
let the LSB be for quiz 1, the next one is for quiz 2, . . . 
0 means unattended, 1 means attended
there are total of  8 quizzes; initally all unattended
*/
int main(){
    unsigned char attendance = 0x00; //? 0000 0000
    unsigned char mask = 0x01;       //? 0000 0001

    attendance = attendance | mask;  // for first quiz
    cout<<bitset<8>(attendance)<<endl;
    //! if attended to third quiz
    mask = mask << 2;                //! 0000 0100 shifted version
    attendance = attendance | mask;
    cout<<bitset<8>(attendance)<<endl;

//! to print attendend quizes 
    mask = 0x01;
    for(int i = 1; i <= 8; i++){
        if(mask & attendance){
            cout << "Student attended quiz number " << i << endl;
        }
        else{
            cout << "Student missed quiz number " << i << endl;
        }
        mask = mask << 1;
    }
    return 0;
}