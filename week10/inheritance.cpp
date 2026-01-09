#include <iostream>
#include <string> 
using namespace std;
/*class Pet{  //Supperclass(base class)
    public:
        Pet():weight(1),food("Pet Chow"){}
        ~Pet(){}

        void setWeight(int w)   {weight = w;}
        int getWeight() const {return weight;}

        void setFood(string f){food = f;}
        string getFood() const{return food;}

        void eat();
        void speak();
    protected:      //! Only subclasses can inherit protected vars
        int weight;
        string food;
};
void Pet::eat(){cout<<"eating food: "<<food<<endl;}
void Pet::speak(){cout<<"Growl"<<endl;}

//! Declaring a new subclass:
class Rat: public Pet{  //Subclass (derived class)
    //Other methods can be added
    public: 
        Rat(){}
        ~Rat(){}
        void sicken(){cout <<"Spreading Plague"<<endl;}
};
class Cat: public Pet{  //Subclass (derived class)
    public:
        Cat(){}
        ~Cat(){}
};
int main(){
    Rat charles;
    Cat fluffy;

    charles.setWeight(35);
    cout<<"Charles weighs "<<charles.getWeight()<<" kilos.\n";

    charles.speak();
    charles.eat();
    charles.sicken();

    fluffy.speak();
    fluffy.eat();
    return 0;
}*/
/*
?   You can derive a subclass in 3 different ways:
*       class Rat: public Pet
&           public: as usual, any class/function can access these variables/methods and 
&           subclass also inherit and access  them
*       class Rat: public Pet
&           private: as usual, no other class/function can access these variables and 
&           subclasses inherit but CANNOT access these members
*       class Rat: protected Pet
&           protected: no other classes/functions can access them, but subclasses 
&           inherit and accessthem (so it is a relaxed form of private)     


*/

class Pet{
    public:
        Pet():val(1){
            cout<<"BASE constructor called!\n";
        }
        Pet(int v, int a):val(v),age(a){
            cout<<"BASE constructor with parameter called!\n";
        }
        Pet(const Pet& other){
            cout<<"BASE ctor called!\n";
            val = other.val;
            age = other.age;
        }
        virtual ~Pet(){
            cout<<"BASE destructor called!\n";
        }

        virtual void speak(){cout<<"hello PET!\n";}
    protected:
        int val;
        int age;
};
class Cat: public Pet{
    public:
        Cat(){
            cout<<"CAT constructor called!\n";
        }
        Cat(int v, int a):Pet(v,a){
            cout<<"CAT constructor with parameter called!\n";
        }
        Cat(const Cat& other){
            //firstly base class ctor will be called!
            cout<<"CAT copyctr called!\n";
            id = other.id;
        }
        ~Cat(){
            cout<<"CAT destructor called!\n";
        }

        virtual void speak() override{cout<<"Hello CAT! \n";}
    protected:
        int id;
};
int main(){
/*
!   Example of object slicing
    Pet a = Cat();
    a.speak();
*/
/*
!   Example of polymorphism
    Pet *a = new Cat();
    (*a).speak();
&   or
    Cat c;
    Pet &a = c;
    a.speak();
*/  
    Pet *a = new Cat();
    (*a).speak();
    delete a;
    return 0;
}