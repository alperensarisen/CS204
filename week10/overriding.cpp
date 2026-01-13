#include <iostream>
#include <string>
//! I implement it again to practice :)
using namespace std;
class Pet{
    public:
        Pet():weight(1),age(1){}
        Pet(int w, int a):weight(w),age(a){}

        void setAge(const int & a){age = a;}
        int getAge() const{return age;}

        void setWeight(const int & w){weight = w;}
        int getWeight() const{return weight;}
//!     We implemented speak function in here but we can make some changes in subclass(es).
        void speak();
        void speak(int times);
    protected:
        int weight;
        int age;
};
void Pet::speak(){
    #ifdef _DEBUG
        cout<<"speak function from pet class\n";
    #endif
    cout<<"Sound!\n";
}
void Pet::speak(int times){
    for(int i = 0 ; i<times; i++)
        cout<<"Sound!\n";
}
class Cat: public Pet{
    public:
        Cat(){}
        Cat(int w, int a):Pet(w,a){}
        void speak();               //! we need to declare if we make change.
        void speak(int a);
};  
void Cat::speak(){cout<<"Meoww!\n";}
void Cat::speak(int a){             //! we can not use this without declare again
    for(int i = 0 ; i<a; i++)
        cout<<"Meow!\n";
}
int main(){
    Pet ex(2,1);
    Cat garfield(10,5);
    ex.speak();
    garfield.speak(5);
}   