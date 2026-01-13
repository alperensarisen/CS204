#include "user.h"
#include <iostream>
#include <string>

user::user(string n, string i):name(n),id(i){};
void user::borrowBook(book & book){
    book.borrowBook();
}
void user::returnBook(book & book){
    book.returnBack();
}
string user::displayInfo(){
    return "User: " +name+", ID: "+id;
}