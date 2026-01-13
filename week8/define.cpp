#include <iostream>
#define PRINT(x) std::cout<<x<<std::endl;
#define UNTIL(x, y) while(x > y)
#define TIME(time) for(int i = 0; i<(int)time ; i++)
#define range(i, start, end) for(int i = (start); i < (end); i++)
#define LOG(x) std::cout<<__FILE__<<":"<<__LINE__<<" | "<< x <<std::endl;
using namespace std;
int main(){
    //PRINT("a");
    //PRINT(1);
    int x = 0;
    UNTIL(5,x){
        PRINT(x);
        x++;
    }
    TIME(5){
        PRINT("TIME");
    }
    int k;
    range(k,1,5){PRINT("RANGE");}
    LOG("To send a message to log");
    return 0;
}