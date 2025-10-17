//!void qsort(
//! void *base,                                 // base of array which will be sorted
//! size_t num_elements,                        // number of elements in array
//! size_t element_size,                        // size of elements sizeof(type...)
//! int (*compare)(const void *, const void *)  // comparing function );

#include <iostream>
using namespace std;
void opperate(int a, int b, int (*ptr) (int,int)){
    cout<<"Result is: "<<ptr(a,b)<<endl;
}
int add(int a, int b){return a+b;}
int multp(int a, int b){return a*b;}
int f1(int a){return 5;}
int sorter(const void *arg_1,const void *arg_2){

    //!(int*) is used for convert type to int pointer then by dereferencing we can reach the value.

    int first = *(int*)arg_1;
    int second = *(int*)arg_2;
    if(first<second) return -1;
    else if(first == second) return 0;
    else return 1;
}
int main(){
    //? Functions are also in stored memory.
    //ret_type (*pointer_name)(arg_type1, arg_type2, ...);
    double f2(char, char);
    int (*pf)(int) = f1; //! is a valid statement but you can also use &f1
    //!int (*pf) (int) = f2; will not be a valid.
    //! First, the return types are not same (int and char)
    //! Second, the number of parameters is not same
    opperate(3,4,add);
    opperate(3,4,multp);

    int array[10];
     /* fill array */
    for (int i = 0; i<10; i++){
        array[i] = ((10 - i) + 5) % 10;
    }
    for ( int j = 0; j < 10; ++j ) { //! to print elements of array.
        cout << array[j] << " ";
    }
    cout << endl;
    qsort(array,10,sizeof(int),sorter);
    for ( int j = 0; j < 10; ++j ) { //! to print elements of array.
        cout << array[j] << " ";
    }
    return 0;
    
}