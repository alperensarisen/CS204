#include <iostream>
#include <string>
#define _DEBUG
using namespace std;
class Clothes{
    public:
        Clothes():price(100),color("White"){}
        Clothes(int p):price(p){}
        Clothes(int p, string c):price(p),color(c){}
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
    public:
        Jacket(){
            #ifdef _DEBUG
                cout<<"Jacket constructor called! \n";
            #endif
        }    //! Jacket():Clothes(){} samething
        Jacket(int p):Clothes(p){}
        Jacket(int p,string c):Clothes(p,c){
            #ifdef _DEBUG
                cout<<"Jacket constructor with parameter called! \n";
            #endif
        }
        ~Jacket(){
            #ifdef _DEBUG
                cout<<"Jacket deconstructor called! \n";
            #endif
        }
};
int main(){
    Jacket JJ;
    JJ.setColor("Black");
    JJ.setPrice(200);
    Jacket LV(154,"red");
    return 0;
}