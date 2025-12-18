#include <iostream>
using namespace std;
class Vehicle{              //abstract class
    public: 
        Vehicle():acc(1){}
        virtual ~Vehicle(){}

        virtual void accelerate() const = 0;    //! = 0 should be only in declaration
        virtual void decelerate() const = 0;
        
        void setAcc(int a){acc = a;}
        int getAcc() const{return acc;}
    protected:
        int acc;
};
void Vehicle::decelerate() const{               //& const = 0 only should be in declaration
    cout<<"Friction decelerates all vehicles\n";
}
class Car:public Vehicle{
    public:
        Car(){}
        virtual ~Car(){}
        virtual void accelerate() const{cout<<"Car Accelerating\n";}
        virtual void decelerate() const{
            cout<<"Car Decelerating\n";
            Vehicle::decelerate();  //! Chaining Up
        }

        virtual void drive() const{cout<<"Car driving...\n";}
};
int main(){
//!Vehicle V; it is not possible, since Vehicle is abstract class
   Car c;
   c.decelerate();
}