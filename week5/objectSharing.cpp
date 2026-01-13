#include <iostream>
#include <string>
using namespace std;
class Player{
    
        
    public:
        string name;
        int score;
        Player(string n, int s):name(n),score(s){};
        
};
class Toy{
    public:
        Toy(const string& name);
        void play();
        void breaks();
    private:
        string myName;
        bool working;
};
//* CONSTRUCTOR
Toy::Toy(const string &name){
    myName = name;
    working = true;
}
void Toy::play(){
    if(working){cout<<"this "<< myName <<" is so fun :-) \n";}
    else{cout<<"this "<< myName <<" is broken :-( \n";}
}
void Toy::breaks(){
    working = false;
    cout<<"opps, this "<<myName<<" just broke \n\n";
}
class kid{
    public:
        kid(const string & name, Toy & toy);
        void play();
    private:
        string myName; //! Name of the kid
        Toy &myToy;    //! instead of clonning to toy object, we decided to use same memory (reference),
                       //! by doing that we are able to use same object in many different kid objects.
};                     //! Using pointer is also a method, but reference is recommended
kid::kid(const string &name, Toy & toy):myName(name),myToy(toy){};
void kid::play(){
    cout<<"My name is "<<myName<< ", ";
    myToy.play();
}
int main(){
    Toy atoy("ball");

    kid Erich("Erich", atoy);
    kid Katie("Katie", atoy);

    Erich.play(); Katie.play();
    atoy.breaks();
    Erich.play(); Katie.play(); 
    
    
    
    
    
    
    
    /*Player p1("alperen", 200);
    Player &p2 = p1;
    //! p2 is not a replication of p1, they are using same memory so that we can define them as a same variable
    p2.score = 100;
    cout<<p2.score;
    //! Any change in p2 will affect p1 and any change in p1 will affect p2, because they are using same place in memory
    return 0;
    */
}