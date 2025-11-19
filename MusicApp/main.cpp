#include "playList.h"
#include "song.h"
#include "iterator.h"
#include <iostream>
#include <string>
using namespace std;
void printList(const playList & list){
    Iterator itr(list);
    for(itr.Init();itr.HasMore();itr.next()){
        cout<<itr.current()<<endl;
    }
}
int main(){
    playList myPlayList;
    myPlayList += Song("I wanna be yours","Arctic Monkeys");
    myPlayList += Song("Better as One","The heavy");
    myPlayList += Song("505","Arctic Monkeys");
    
    cout<<"PlayList:\n"<<myPlayList<<endl;

    playList archive = myPlayList;      //! copy constructor
    playList AllSongs =  archive + myPlayList;

    cout<<"All songs:\n"<<AllSongs<<endl;

    if(archive == AllSongs){
        cout<<"All songs already archived"<<endl;
    }
    printList(myPlayList);
    return 0;
    
}