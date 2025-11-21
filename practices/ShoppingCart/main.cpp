#include <iostream>
#include "Cart.h"
using namespace std;

int main() {
    // 1) Create some products
    product p1("Milk", 2.5);
    product p2("Bread", 1.2);
    product p3("Chocolate", 0.8);

    // 2) Add products to the first cart (operator+=)
    cart c1;
    c1 += p1;
    c1 += p2;

    cout << "Cart c1:\n";
    cout << c1 << endl;

    // 3) Test copy constructor
    cart c2(c1);
    cout << "Cart c2 (copy of c1):\n";
    cout << c2 << endl;

    // 4) Add an extra product to make c2 different
    c2 += p3;

    cout << "Cart c2 after adding Chocolate:\n";
    cout << c2 << endl;

    // 5) Test operator+
    cart c3 = c1 + c2;
    cout << "Cart c3 (c1 + c2):\n";
    cout << c3 << endl;
    return 0;
}