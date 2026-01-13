#include <iostream>
#include <string>
using namespace std;
class Book{
    private:
        string name;
        string author;
    public:
        Book(string n, string a);
        ~Book();
        string Display_info();
};
Book::Book(string n, string a):name(n),author(a){} //! Constructor

Book::~Book(){                                     //! Destructor                
    cout<<"Object "<<name<<" is destroying\n";     //! it not takes parameter
}                                                  //!
string Book::Display_info(){
    return "Title: "+name+", Author: "+author;

}
int main(){
    Book b("book1", "Mark");
    Book *p;
    cout<<b.Display_info()<<endl;
    {//nested scope
        cout<<"---in nested bracekts---\n";
        Book b2("book2", "David");
        p = new Book("book3","victor");
    }
    cout<<"---Out brackets---\n";
    cout<<"deleting p ...\n";
    delete p;
    return 0;
}