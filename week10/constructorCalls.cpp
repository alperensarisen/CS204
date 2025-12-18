#include <iostream>
#include <cstring>
#define _DEBUG
using namespace std;
class Clothes{
    public:
        Clothes():price(100),color("White"){}
        Clothes(int p):price(p){}
        Clothes(int p, string c):price(p),color(c){}
    //! If we do not define a copy constructor, the compiler will create a default one for us
    //! which performs a shallow copy (member-wise copy)

        Clothes(const Clothes& other){              //& Copy constructor
            price = other.price;
            color = other.color;
        }
        ~Clothes(){}

        void setPrice(int p){price = p;}
        int getPrice() const{return price;}

        void setColor(string c){color = c;}
        string getColor() const{return color;}
    protected:
        int price;
        string color;
};
class Jacket: public Clothes{
    char* c_type;
    public:
        Jacket(const char* c = "Jacket"){
            c_type = new char[strlen(c)+ 1];
            strcpy(c_type, c);
            #ifdef _DEBUG
                cout<<"Jacket constructor called! \n";
            #endif
        }    //! Jacket():Clothes(){} samething
        /*Jacket(int p, const char* c = "Jacket"):Clothes(p){
            c_type = new char[strlen(c) + 1];       //! allocate memory and +1 for \0
            strcpy(c_type, c);
            #ifdef _DEBUG
                cout<<"1. Jacket constructor with parameter called! \n";
            #endif
        }*/
        Jacket(int p,string c, const char *str = "Jacket"):Clothes(p,c){
            c_type = new char[strlen(str) +1];
            strcpy(c_type,str);
            #ifdef _DEBUG
                cout<<"2. Jacket constructor with parameter called! \n";
            #endif
        }
        //! COPY CONSTRUCTOR
        Jacket(const Jacket & other):Clothes(other){
            #ifdef _DEBUG
                cout<<"Jackets copy constructor called!\n";
            #endif
            c_type = new char[strlen(other.c_type) + 1];
            strcpy(c_type, other.c_type);
            //! We are copying them with base class copy constructor
            //price = other.price;
            //color = other.color;
        }
        ~Jacket(){
            #ifdef _DEBUG
                cout<<"Jacket deconstructor called! \n";
            #endif
            delete[] c_type;
        }
        void printType(){
            cout<<"Type is: "<<c_type<<endl;
        }
};
int main(){
    Jacket JJ;
    JJ.setColor("Black");
    JJ.setPrice(200);
    Jacket LV(154,"red");
    JJ.printType();
    return 0;
}