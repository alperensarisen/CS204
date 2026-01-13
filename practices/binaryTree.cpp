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
void AddRec(node* &root, int val){
    if(!root){
        root = new node(val);
        return;
    }
    if(val > root->value){
        AddRec(root->right,val);
    }
    else if(val < root->value){
        AddRec(root->left,val);
    }
    else{
        cout<<val<<" is already in tree :)"<<endl;
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
int heightOfTree2(node* root){
    if(!root) return 0;
    int right = heightOfTree2(root->right);
    int left = heightOfTree2(root->left);
    return 1 + max(right,left);
}
int HOT(node* root){
    if(!root) return 0;
    
    return 1 + max(HOT(root->left),HOT(root->right));
}
int countNodes(node* root){
    if(!root) return 0;
    int a = countNodes(root->left);
    int b = countNodes(root->right);
    return 1+a+b;
}
int CN(node* root){
    if(!root) return 0;
    return 1 + CN(root->right) +CN(root->left);
}
int countLeafNodes(node *root){
    if(!root) return 0;
    if(!root->right && !root->left) return 1;
    int a = countLeafNodes(root->right);
    int b = countLeafNodes(root->left);
    return a + b;                             //* return countLeafNodes(root->right)+countLeafNodes(root->left); also true
}
int CLF(node *root){
    if(!root) return 0;
    int count = 0;
    if(!root->left && !root->right) count = 1;
    return count + CLF(root->right) +CLF(root->left);
}
//! --------- IMPORTANT :) --------------
node* search(node* root, int v){
    if(!root) return nullptr;
    if(root->value == v ) return root;
    node* leftResult = search(root->left,v);
    if(leftResult) return leftResult;
    return search(root->right,v);
}
node* search2(node* root, int v){
    if(!root) return nullptr;
    if(root->value == v) return root;
    node* leftR = search2(root->left,v);
    if(leftR) return leftR;
    return search2(root->right,v);
    }
//* #################### LEVEL 2 ###################
int countFullNodes(node *root){
    if(!root) return 0;
    int count = 1;
    if(root->right && root->left) count = 1;
    return count + countFullNodes(root->right) + countFullNodes(root->left);
}
int countFullNodes2(node *root){
    if(!root) return 0;
    int count = 1;
    if(root->left && root->right) count = 1;
    return count +countFullNodes2(root->right) + countFullNodes2(root->left);
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
        for(int  i = 0;i < size; i++){
            node *n = q.front();
            q.pop();
            cout<<n->value<<" ";

            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        cout<<endl;
    }
}
int main(){
    node* r = new node(1);
    AddRec(r,5);
    AddRec(r,3);
    AddRec(r,9);
    AddRec(r,2);
    AddRec(r,4);
    AddRec(r,8);
    AddRec(r,11);
    AddRec(r,7);
    AddRec(r,10);

    InOrderPrint(r);
    cout<<endl;
    levelOrderPrint(r); 
    cout<<"\nheight of tree: "<<heightOfTree(r)<<endl;
    cout<<"height of tree2: "<<heightOfTree2(r)<<endl;
    cout<<"height of tree3: "<<HOT(r)<<endl;
    cout<<"\nCount of leaf nodes: "<<countLeafNodes(r)<<endl;
}
