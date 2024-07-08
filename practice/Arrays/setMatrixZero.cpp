#include "bits/stdc++.h"
using namespace std;



void setZero(vector<vector<int>> &matrix, int n, int m){
    vector<int> cols(m, 0);
    vector<int> rows(n, 0);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }


    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(rows[i] == 1 || cols[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
}


void printMatrix(vector<vector<int>> &matrix, int n, int m){
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
}

int main(){
    vector<vector<int> > matrix = {
        {1, 98, 1, 3},
        {1, 53, 1, 6},
        {1, 88, 0, 12},
        {1, 11, 9, 23}        
        };
        
    int m = matrix[0].size();
    int n = matrix.size();
    printMatrix(matrix, n, m);
    setZero(matrix, n, m);
    cout << "\n\n";
    printMatrix(matrix, n, m);

    // cout << "rows:  " << n << "\ncolumns:   " << m <<endl;
    
    return 0;
}