#include <iostream>
#include <vector>
using namespace std;
void matrixPrinter(vector<vector<int>> mtrx){
    for(int i  =0; i<mtrx.size();i++){
        for(int j = 0; j<mtrx[i].size(); j++){
            cout<< i+1 <<"th row "<< j+1 << "th column equals to "<<mtrx[i][j]<<endl;
        }
    }
}//basic matrix printer function.

int main(){
    //represantation of matrix
    int row = 5;
    int column = 10;
    int init_value = 1;  
    //all elements in the matrix will be init_value which is equal to 1.
    vector<vector<int>> mat(row,vector<int>(column, init_value));
    matrixPrinter(mat);
    //by using init_value we will see 1 for every element.
    //if there was not any init_value, all elemnets would be 0.
    cout<<mat.size()<<endl;     //number of row in matrix
    cout<<mat[0].size()<<endl;  //number of column in matrix
    return 0;
    
}