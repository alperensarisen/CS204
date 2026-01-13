#ifndef CART_H_
#define CART_H_
#include "product.h"
#include <iosfwd>
using namespace std;
class cart{
    friend class Iterator;
    private:
        struct node
        {
            product data;
            node *next;
            node(product d, node* n):data(d),next(n){}
        };
        node *head;
        int size;
    public:
    cart();
    cart(const cart& other);
    ~cart();
    
    void copyFrom(const cart& other);
    void clear();
    void printList() const;
    cart &operator=(const cart& rhs);
    cart &operator+=(const product& product);
    cart operator+(const cart rhs) const;
    bool operator==(const cart &rhs) const;
    int getSize() const;
    friend ostream &operator<<(ostream& out,const cart& list);
};
#endif