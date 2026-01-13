#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "user.h"
#include "book.h"

using namespace std;

class library{
    
    public:
        vector<book> books;
        void addBook(book &book);
        void displayBooks();
};
void library::addBook(book &book){
    books.push_back(book);
    cout<<"New book added to library.\n";
}
void library::displayBooks(){
    for(int i = 0; i<books.size(); i++){
        cout<<books[i].displayInfo()<<endl;
    }
}
void display_Users(vector<user> &usr){
    for(int i = 0; i<usr.size();i++){
        cout<<usr[i].displayInfo() <<endl;
    }
}
void display_Book(vector<book> &bkr){
    for(int i = 0; i<bkr.size();i++){
        cout<<bkr[i].displayInfo() <<endl;
    }
}
int main(){
    vector<user> users;
    vector<book> books;
    
    ifstream User_file("users.txt");
    ifstream Books_file("books.txt");
    library lib;
    if(User_file.fail() || Books_file.fail()){
        cout<<"Some error has occured!"<<endl;
        return 1;
    }

    string line;
    while(getline(User_file,line)){
        string name, id;
        size_t pos = line.find('-');
        if(pos != string::npos){
            name = line.substr(0, pos);
            id = line.substr(pos + 3);
            users.push_back(user(name,id));
        }
    }
    string line2;
    while(getline(Books_file,line2)){
        string bookN,Aut;
        size_t pos2 = line2.find('-');
        if(pos2 != string::npos){
            bookN = line2.substr(0, pos2);
            Aut = line2.substr((pos2)+3);
            book b(bookN,Aut);
            lib.addBook(b);
        }
    }
    //display_Users(users);
    //display_Book(books);
    
    
    
    
    
    return 0;
}