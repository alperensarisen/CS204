#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "song.h"
#include "Iterator.h"
#include<iosfwd>
class playList{
    friend class Iterator;
    private:
        
        struct node{
            Song data;
            node *next;
            node(Song d, node *n = nullptr):data(d),next(n){};
        };
        node *head;
        int size;

        void clear();
        void CopyFrom(const playList& other);
        public: 
            playList();                         //! Default constructor
            playList(const playList& other);    //! Copy constructor
            ~playList();                        //! Destructor

            playList & operator+=(const Song& rhs);
            playList & operator=(const playList& rhs);
            playList operator+(const playList& rhs) const;

            bool operator==(const playList& pl) const;
            int getSize(){return size;}

            friend ostream& operator<<(ostream& out, const playList& pl);
};
#endif