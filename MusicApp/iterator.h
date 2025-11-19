#include <iostream>
#include <string>
#include "playList.h"
using namespace std;
class Iterator{
    public: 
        Iterator(const playList & list):LL(list),myCurrent(nullptr){}
        void Init(){
            myCurrent = LL.head;
        }
        bool HasMore(){return (myCurrent != nullptr);}
        string current(){
            return myCurrent->data.title;
        }
        void next(){myCurrent = myCurrent->next;}
    private:
        const playList & LL;
        typedef playList::node node;
        node* myCurrent;
};
