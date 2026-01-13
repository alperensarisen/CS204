#include "book.h"
#include <iostream>
#include <string>
using namespace std;

book::book(string n, string a):bookName(n),author(a){};
void book::borrowBook(){
    isBorrowed = true;
    cout<<"The "<<bookName<<" borrowed!\n";
}
void book::returnBack(){
    isBorrowed = false;
    cout<<"The "<<bookName<<" returned back!\n";
}
string book::displayInfo(){
    return "Title: "+bookName + ", Author: " + author;
}