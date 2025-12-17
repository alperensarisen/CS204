#include <iostream>
#include <string> 
using namespace std;
class Pet{
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
class Rat: public Pet{  //Other methods can be added
    public: 
        Rat(){}
        ~Rat(){}
        void sicken(){cout <<"Spreading Plague"<<endl;}
};
class Cat: public Pet{
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