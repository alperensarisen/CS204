#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <string>
using namespace std;
class message{
    public:
        message(const string& text,const string& name);
        string msg;
        string sender;
};

#endif