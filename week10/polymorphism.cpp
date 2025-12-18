#include <iostream>
using namespace std;
class CBox{
    public:
        CBox():w(1),h(1),l(1){}
        CBox(int _w, int _h, int _l):w(_w),h(_h),l(_l){}
        void printType(){cout<<"I'm a box!\n";}
        virtual int volume() const{return w*l*h;}
    /*
    !   If virtual is not used, the output is 1 5.
    !   This is because the compiler decides which function to call based on the pointer type (static binding).

    !   However, when the virtual keyword is used, the output becomes 5 5.
    !   In this case, the compiler determines which function to call based on the actual type of the object at runtime (dynamic binding).
    */
        protected:
        int w,h,l;
};
class CCandyBox: public CBox{
    public:
        CCandyBox():CBox(){}
        CCandyBox(int _w, int _h ,int _l):CBox(_w,_h,_l){}
        int volume() const{return 5*w*h*l;}
};
int main(){
    CBox *p_b = new CBox();
    CCandyBox *p_c = new CCandyBox(1,1,1);
    p_b = p_c;
    cout<<p_b->volume()<<endl;
    cout<<p_c->volume()<<endl;
    return 0;
}