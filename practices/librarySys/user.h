
#ifndef USER_H_
#define USER_H_
#include <string>
#include "book.h"
using namespace std;
class user{
    private:
        string name;
        string id;
    public:
        user(string n, string i); //! Constructor
        void borrowBook(book &book);
        void returnBook(book &book);
        string displayInfo();
        
};
#endif
