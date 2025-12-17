#include <iostream>
using namespace std;

class CBox{
    public:
        CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0):
        m_Lenght(lv),m_Breadth(bv),m_Height(hv){}

    protected:
        double m_Lenght;
        double m_Breadth;
        double m_Height;
//! friend CCandyBox;   
        //we can reach private datas from subclass(not so good)
        //instead of this protected: is better
};
class CCandyBox: public CBox{
    char* m_Contents;
    double Volume() const{
        return m_Lenght*m_Breadth*m_Height;
    }
    CCandyBox(char *str = "Candy"){
        m_Contents = new char[strlen(str) + 1];
        strcpy(m_Contents, str);
    }
    ~CCandyBox(){delete[] m_Contents; }
};
/*
&   Constructors, including copy constructors, and destructors are NOT inherited. 
?        Each derived class has its own constructor and destructor.


*/