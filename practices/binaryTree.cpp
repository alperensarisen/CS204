#include<iostream>
using namespace std;
struct binaryTree
{
    int value;
    binaryTree *right;
    binaryTree *left;
    binaryTree(int v):value(v),right(nullptr),left(nullptr){}
};
void addNode(binaryTree *&root,int n){
    binaryTree *ptr = root;
    binaryTree *nn = new binaryTree(n);
    if(!root) root = nn;
    else{
        while (ptr)
        {
            if(n < ptr->value){
                if(ptr->left){
                    ptr = ptr->left;
                }
                else{
                    ptr->left = nn;
                    break;
                }
            }
            else if(n > ptr->value){
                if(ptr->right){
                    ptr = ptr->right;
                }
                else{
                    ptr->right = nn;
                    break;
                }
                
            }
            else{
                cout<<"This tree already has "<<n<<" element\n";
                break;
            }
        }
    }
}
void displayInOrder(binaryTree *root){
    if(root){
        displayInOrder(root->left);
        cout<<root->value<<endl;
        displayInOrder(root->right);
    }
}
void preOrder(binaryTree * root){
    if(root){
        cout<<root->value<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(binaryTree * root){
    if(root){
        postOrder(root->right);
        cout<<root->value<<endl;
        postOrder(root->left);
    }
}
int main(){
    binaryTree *root1;
    root1 = new binaryTree(1);
    addNode(root1, 2);
    addNode(root1, 5);
    addNode(root1, 4);
    addNode(root1, 3);
    addNode(root1, 3);
    cout<<"display in order: \n";
    displayInOrder(root1);
    cout<<"display in pre order: \n";
    preOrder(root1);
    cout<<"display in post order: \n";
    postOrder(root1);

}
