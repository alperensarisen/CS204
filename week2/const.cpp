#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int b = 20;
    int* const ptr = &a;
    //? it points always same address but value can be changed
    const int* ptr2 =&a; 
    //? it can point a different address but value cant be changeed.
    cout<<*ptr<<endl;
    //! ptr = &b; it will not be possible but
    *ptr = 11; //* it will be possible
    cout<<*ptr<<endl;
    ptr2 = &b; //? it will be possible but
    //! *ptr2 = 1; it is not possible
 //? int* - pointer to int */
 //? int const * - pointer to const int */
 //? int *const - const pointer to int */
 //? int const *const - const pointer to const int */

 //? Now the first const can be on either side of the type so: */
 //? const int * == int const * */
 //? const int * const == int const * const */

 //? You can do things like this: */
 //? int ** - pointer to pointer to int */
 //? int **const - a const pointer to a pointer to an int */
 //? int *const * - a pointer to a const pointer to an int */
 //? int const ** - a pointer to a pointer to a const int */
 //? int * const * const - a const pointer to a const pointer to an int */
 //? const int* foo; */
 //? int *const bar;  //note, you actually need to set the pointer 
 //? //here because you can't change it later */

    return 0;
}