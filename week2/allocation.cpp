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
        Person() : name(""), surname(""), age(0) {}
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
    cout <<"The address of p1 is: "<<p_Person<<endl;
    cout <<p_Person->age<<endl;
    // ptr->is a shorthand for (*ptr).
    Person *P1p = new Person;
    P1p = &p1;
    cout<<"The age of p1 object is: " <<P1p->age<<endl;
    //
    //int *p_1, *p_2;
    //p_1 = new int;      // it allocates enough memory for a single int
    //p_2 = new int[4];   //it allocates memory for 4 integers.
    int *primenumbers = new int[100];
    primenumbers[0] = 2;
    primenumbers[1] = 3;
    cout << "First prime is " << primenumbers[0]<<endl;
    // primenumbers[0] and *primenumbers are the same thing
    cout<<*(primenumbers+1)<<" is equal to "<<primenumbers[1]<<endl;
    //In general, ptr+x means, the xth memory location (of the type of ptr) in the memory after ptr.

    int myArray[100];
    int *pInt = &(myArray[5]);
    int *pInt2 = &(myArray[10]);
    cout<<pInt<<" && "<<pInt2<<endl;
    cout<<pInt2-pInt<<endl;
    //!The difference between the memory locations is not 5 indeed. But in
    //!pointer arithmetic it is… Every object takes a space in memory. A
    //!single int is 32 bits (4 bytes) in memory. So 5 ints make 20 bytes
    //!which is 14 (38 – 24) in hexadecimal representation.
    cout<<"Bytes between them: "<<(char*)pInt2 - (char*)pInt<<endl;
    return 0;
}