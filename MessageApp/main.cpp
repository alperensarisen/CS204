#include <iostream>
#include "Message.h"
#include "MessageList.h"
using namespace std;

int main(){
    MessageList inbox;
    inbox += message("selam","Kamer");
    inbox += message("merhaba","Jack");

    cout<<"Inbox:\n"<<inbox<<endl;

    MessageList archive = inbox; //! Copy constructor
    MessageList all = archive + inbox;

    cout<<"All messages:\n"<<all<<endl;

    if(inbox == archive){
        cout<<"Your messages already archived! "<<endl;
    }
    return 0;
}