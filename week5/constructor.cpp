#include <iostream>
using namespace std;
class Point{
    public:
        Point(); //! Default constructor
        Point(int xx, int yy); //! Constructor with parameters
    private:
        int x;
        int y;
};
Point::Point(){
    x = 0;
    y = 0;
};
Point::Point(int xx, int yy){
    x = xx;
    y = yy;
}
//! if no constructor was defined, 
//! then a created object have two integers x and y with no initial values
//* other methos for constructors
Point::Point(int xx, int yy):x(xx),y(yy){}; //? INITIALIZER LIST
int main(){
    
    
    return 0;
}