#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
#include <string>
using namespace std;
class product{
    public:
        string name;
        int weigh;
        product(string n, int w):name(n),weigh(w){}
        
};
#endif