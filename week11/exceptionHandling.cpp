#include <iostream>
#include <string>
using namespace std;
double toInches(int cm){
    if(cm == 100)
        throw "You are the winner";
    return cm/2.54;
}
int main(){
    int height;
    int input;
    cout<<"Enter height: ";
    cin >> height;
//! If everything is normal, then code will pass the catch part
//! If something goes wrong when code of try block is executed, this code 
//! throws an exception object and stops executing the code of try block further

    try
    {
        if(height < 0)
            throw 0;
        if(height>300)
            throw "height exceeds maximum";
        if(height<30)
            throw "height exceeds minimum";
        cout<<"Person is "<<toInches(height)<<" inches tall\n";
    }
    //no statements are allowed between try and catch :)
    catch(const char msg[])         //! if there are more than 1 catch, then their parameter types must be different
    {
        cout << "Exception occured: " << msg << endl;
    }
    catch(int i){
        cout<<"A person can not be shorter than "<<i<<endl;
    }
    cout<<"The height is "<<height<<endl; 
//& You must supply at least one catch block for a try block Otherwise compiler error

    string s = "BLA BLA";
    cin >> input;
    try
    {
        if (input == 1) throw 1.1; 
        if (input == 2) throw 2;
        if (input == 3) throw "bla bla";
        if (input == 4) throw s;
    }

    catch (double i)
    { cout << "Double exception handler" << endl;
    }
    catch (int i)
    { cout << "Integer exception handler" << endl;
    }
    catch(const char msg[])
    { cout<<"char array exception handler" <<endl;
    }
    catch(string s)
    { cout << "String exception handler" << endl;
    }
    return 0;
}