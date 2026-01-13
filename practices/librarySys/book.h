#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;
class book{
    string bookName;
    string author;
    bool isBorrowed;
    public:
        book(string t, string a);
        void borrowBook();
        void returnBack();
        string displayInfo();
};
#endif