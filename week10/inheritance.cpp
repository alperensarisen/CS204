#include <iostream>
#include <string> 
using namespace std;
class Pet{  //Supperclass(base class)
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
}
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