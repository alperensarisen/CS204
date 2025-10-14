#include <iostream>
#include <string>
using namespace std;
class Person{ //very basic person class for practice
    private:
        string name, surname;
        
    public:
        int age;
    //constructor
        Person(string n, string s, int a)
        : name(n),surname(s),age(a){}
    void printInfo(){
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
    }
};
int main(){
    Person p1("Alperen","Sarisen",21);
    p1.printInfo();
    Person *p_Person; //this is a class type pointer
    p_Person = &p1; //pointer points to address of p1 object
    cout <<"The address of p1 is "<<p_Person<<endl;
    cout <<p_Person->age<<endl;
    // ptr->is a shorthand for (*ptr).
   
    return 0;
}