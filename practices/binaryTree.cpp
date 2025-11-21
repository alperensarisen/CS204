#include<iostream>
#include <queue>
using namespace std;
struct node
{
    int value;
    node *right;
    node *left;
    node(int v):value(v),right(nullptr),left(nullptr){}
};
//* ################## LEVEL 1 ######################
void addInOrder(node* &root, int val){
    if(!root){
        root = new node(val);       //! There is a memory leadk in here but I will not fix it  :)
        return;
    }
    node* temp = root;
    node* nn = new node(val);
    while(temp){
        if(val < temp->value){
            if(temp->left){
                temp = temp->left;
            }
            else{
                temp->left = nn;
                break;
            }
        }
        else if(val > temp->value){
            if(temp->right){
                temp = temp->right;
            }
            else{
                temp->right = nn;
                break;
            }
        }
        else{
            cout<<"There is a node which already contains "<<val<<endl;
            break;
        }
    }
}
void InOrderPrint(node* root){
    if(!root) return;           //! base case
    InOrderPrint(root->left);
    cout<<root->value<<" ";
    InOrderPrint(root->right);
}
void PreOrderPrint(node *root){
    if(!root) return;
    cout<<root->value<<" ";
    PreOrderPrint(root->left);
    PreOrderPrint(root->right);
}
void postOrderPrint(node *root){
    if(!root) return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->value<<" ";
}
int heightOfTree(node* root){
    if(!root) return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return 1 + max(left,right);
}
int countNodes(node* root){
    if(!root) return 0;
    int a = countNodes(root->left);
    int b = countNodes(root->right);
    return 1+a+b;
}
int countLeafNodes(node *root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    
    int a = countLeafNodes(root->left);
    int b = countLeafNodes(root->right);
    return a + b;                               //* return countLeafNodes(root->right)+countLeafNodes(root->left); also true
}
//! --------- IMPORTANT :) --------------
node* search(node* root, int v){
    if(!root) return nullptr;
    if(root->value == v ) return root;
    node* leftResult = search(root->left,v);
    if(leftResult) return leftResult;
    return search(root->right,v);
}
//* #################### LEVEL 2 ###################
int countFullNodes(node *root){
    if(!root) return 0;
    int count = 1;
    if(root->right && root->left) count = 1;
    return count + countFullNodes(root->right) + countFullNodes(root->left);
}
int countSingleChild(node* root){
    if(!root) return 0;
    int count = 0;
    if((!root->right && root->left) || (!root->left && root->right)) count = 1;
    return count + countSingleChild(root->left)+countSingleChild(root->right);
}
int minValue(node* root){
    if(!root) return -1;   //! Empty
    node* temp = root;
    while(temp){
        temp = temp->left;
    }
    return temp->value;
}
//!!!! RECURSİVE VERSİON
int minRec(node *root){
    if(!root){
        return -1;
    }
    if(!root->left) return root->value;
    return minRec(root->left);
}

int maxValue(node* root){
    if(!root) return -1;
    node *temp = root;
    while(temp){
        temp = temp->right;
    }
    return temp->value;
}
//!!!!! RECURSİVE VERSİON
int maxRec(node* root){
    if(!root) return -1;
    if(!root->left) return root->value;
    return maxRec(root->left);
}
void levelOrderPrint(node* root){
    if(!root) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size;i++){
            node* nd = q.front();
            q.pop();
            cout<<nd->value<<" ";

            if(nd->left) q.push(nd->left);
            if(nd->right) q.push(nd->right);
        }
        cout<<endl;
    }

}
int main(){
    node* r = new node(1);
    addInOrder(r,5);
    addInOrder(r,3);
    addInOrder(r,9);
    addInOrder(r,2);
    addInOrder(r,4);
    addInOrder(r,8);
    addInOrder(r,11);
    addInOrder(r,7);
    addInOrder(r,10);

    //InOrderPrint(r); 
    levelOrderPrint(r); 
    

}
