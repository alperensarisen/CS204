#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(string a){
    cout<<"first function called: "<<a<<endl;
}
void print(int a){
    cout<<"second function called: "<<a<<endl;
}
//! basic template func
template<typename T>
void change(T & a, T & b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template <typename T>
T myMax(T a, T b){
    return (a > b) ? a : b;
}
//! Swaping values at the given location in a vector
template <class T>
void swap(vector<T> & list, int i, int j){
    T temp;
    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
template <class T>
void printV(const vector<T> & list){
    cout<<"[";
    for(int i = 0; i<list.size(); i++){
        cout<<list[i]<<", ";
    }
    cout<<"]\n";
}
int main(){
    string text = "hello";
    int num = 5;
    print(text);
    print(num);
    //! instead of doing that we can use template funcs.
    cout<<"-----TEMPLATE FUNC-----\n";
    int num1 = 1;
    int num2 = 2;
    string txt1 = "hello";
    string txt2 = "world!";
    cout<<"num1: "<<num1<<" num2: "<<num2<<endl;
    change(num1,num2);
    cout<<"num1: "<<num1<<" num2: "<<num2<<endl;
    cout<<"-----------------------------------\n";
    cout<<"txt1: "<<txt1<<" txt2: "<<txt2<<endl;
    change(txt1,txt2);
    cout<<"txt1: "<<txt1<<" txt2: "<<txt2<<endl;
    //! More useful usage for template funcs
    cout<<myMax('a','c')<<endl;             //* T is char
    cout<<myMax(5,1)<<endl;                 //* T is integer
    cout<<myMax(5.5,1.2)<<endl;             //* T is double
    cout<<myMax(string("David"),string("Jack"))<<endl;      //* T is string
    cout<<"-----------------------------------\n";
    //! Swaping values at the given location in a vector
    vector<int> vec1 = {1,2,3,4,5,6,7};
    vector<char> vec2 = {'a','b','c','d','e','f'};
    vector<double> vec3 = {0.1,1.2,2.3,3.4,4.5,5.6};
    printV(vec1);
    printV(vec2);
    printV(vec3);
    swap(vec1,1,4);
    swap(vec2,1,4);
    swap(vec3,1,4);
    cout<<"Changed versions: \n";
    printV(vec1);
    printV(vec2);
    printV(vec3);
    return 0;
}
//? template types can be return type, but there must be at least 
//? one parameter of template type
//* template <class T>
//* T doThis (int x);  //this is not valid