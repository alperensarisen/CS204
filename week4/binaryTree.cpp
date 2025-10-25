//? A tree is a data structure to hold the nodes 
//? with a parent-child relationship, i.e., 
//? simulates a hierarchical structure.

//? A binary tree is a non-linear linked list 
//? where each node may point to two other 
//? nodes.


#include <iostream>
using namespace std;
struct binaryTree
{
    int value;
    binaryTree *left;
    binaryTree *right;
    binaryTree(int vl){
        value = vl;
        right = nullptr;
        left = nullptr;
    }
};
//! small value will be in the left side,
//! big value value will be in the right
binaryTree *addNew(binaryTree *root, int val){
//! If it is null tree, create a new node for beginning 
    if(root == nullptr){
        return new binaryTree(val);
    }
//? if value is smaller send it to left.
    if(val < root->value){
        root->left = addNew(root->left, val);
    }
//? if value is bigger send it to right.
    else if(val > root->value){
        root->right = addNew(root->right,val);
    }

    return root; 
    //! if there is a same value do not do anything.
}
//! Display in order
void Inorder(binaryTree *root){
    if(root == nullptr) return;
    Inorder(root->left);
    cout<< root->value << " ";
    Inorder(root->right);
}
//! Display pre-order
void PreOrder(binaryTree *root){
    if(root == nullptr) return;
    cout << root->value << " ";
    PreOrder(root->right);
    PreOrder(root->left);
}
//! Display Post order
void PostOrder(binaryTree *root){
    if(root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->value<<" ";
}
int main(){
    binaryTree *root = nullptr;
    root = addNew(root,8);
    root = addNew(root,5);
    root = addNew(root,12);
    root = addNew(root,7);
    root = addNew(root,2);
    cout << "Inorder: ";
    Inorder(root);
    cout<<"\nPre-Order: ";
    PreOrder(root);
    cout<<"\nPost-Order: ";
    PostOrder(root);
    return 0;
}