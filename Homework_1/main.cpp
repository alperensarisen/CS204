#include <iostream>
#include <string>
#include <iomanip>  
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    cout << fixed << setprecision(10);
    ifstream file;
    string file_name;
    string line;
    vector<string> lines;
    cin>>file_name;
    file.open(file_name);
    if(file.fail()){                    //! to check the file is opened or not
        cout<<"There is a problem\n";
        return 1;
    }



    int line_num = 1;
    int size_x, size_y, size_z;         //! the sizes 3D of the tensor
    long double target_sum,value; 
    int num_elemets;
    int cor_x,cor_y,cor_z;
    while(getline(file,line)){
        stringstream ss(line);
        if(line_num == 1){                              //! For the first line.
            ss>>size_x>>size_y>>size_z;
            cout<<"width of tensor is: "<<size_x<<endl;
            cout<<"height of tensor is: "<<size_y<<endl;
            cout<<"depth of tensor is: "<<size_z<<endl;
        }
        else if(line_num == 2){                         //! For the second line.
            ss>>target_sum;
            cout<<"Target sum value: "<<line<<endl;
        }
        else if(line_num == 3){
            ss>>num_elemets;
            cout<<"Tumber of element in the tensor is: "<<line<<endl;
        }
        else{
            lines.push_back(line);
        };
        line_num++;
    }
    vector<vector<vector<long double>>> vec(size_x, vector<vector<long double>>(size_y, vector<long double>(size_z, 0)));
    for(int element = 0; element < lines.size(); element++){
        stringstream ss(lines[element]);
        ss>>cor_x>>cor_y>>cor_z>>value;
        vec[cor_x][cor_y][cor_z]=value;
    }
    
    file.close();
    long long count = 0;

    for (int x1 = 0; x1 < size_x; x1++) {
        for (int y1 = 0; y1 < size_y; y1++) {
            for (int z1 = 0; z1 < size_z; z1++) {
                for (int x2 = x1; x2 < size_x; x2++) {
                    for (int y2 = y1; y2 < size_y; y2++) {
                        for (int z2 = z1; z2 < size_z; z2++) {

                            long double sum = 0.0;

                            for (int i = x1; i <= x2; i++)
                                for (int j = y1; j <= y2; j++)
                                    for (int k = z1; k <= z2; k++)
                                        sum += vec[i][j][k];

                            if (sum == target_sum)   // doğrudan eşitlik kontrolü
                                count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}