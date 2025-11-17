#include "playList.h"
#include <string>
#include <iostream>
#include <iosfwd>
using namespace std;
void playList::clear() {
    node *p = head;
    while(p){
        node *next = p->next;
        delete p;
        p = next;
    }
    head = nullptr;
    size = 0;
}
void playList::CopyFrom(const playList& other){
    head = nullptr;
    size = 0;

    node* temp = other.head;
    while(temp){
        *this += temp->data;
        temp = temp->next;
    }
}
playList::playList():head(nullptr),size(0){}
playList::playList(const playList& other):head(nullptr),size(0){CopyFrom(other);}
playList::~playList(){clear();}

//! += Operator : to add a new music into playlist.
playList &playList::operator+=(const Song& sng){
    node *newSong = new node(sng);
    if(!head)
        head = newSong;
    else{
        node *p = head;
        while(p->next){
            p = p->next; 
        }
        p->next = newSong;
    }
    size++;
    return *this;
}

//! Assignment operator
playList &playList::operator=(const playList& other){
    if(this != &other){
        clear();
        CopyFrom(other);
    }
    return *this;
} 
//! + Operator :: to merge two list
playList playList::operator+(const playList &rhs) const{
    playList result(*this);
    node *p = rhs.head;
    while(p){
        result += p->data;
        p = p->next;
    }
    return result;
}
bool playList::operator==(const playList& other) const{
    node *p1 = head;
    node *p2 = other.head;
    while(p1&&p2){
        if(p1->data.title != p2->data.title && p1->data.artist != p2->data.artist){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
ostream& operator<<(ostream& out, const playList & pl){
    playList::node * p = pl.head;
    int index = 1;
    while(p){
        out<<"["<<index<<"] "<<"Title: "<<p->data.title<<" Artist: "<<p->data.artist<<endl;
        p = p->next;
        index++;
    }
    return out;
}
