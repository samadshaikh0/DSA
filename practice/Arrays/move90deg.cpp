#include "bits/stdc++.h"
using namespace std;



void printMatrix(vector<vector<int>> &matrix, int n, int m){
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void rotateBy90Deg(vector<vector<int> >&matrix){
    int n = matrix.size();

    // 1.Find transpose of the matrix
    for(int i = 0;i<n-2;i++){
        for(int j = 0;j<n;j++){
            matrix[i][j] = matrix[j][i];
        }
    }
    cout << "transposed Matrix: \n";
    printMatrix(matrix,n,n);
    for(int i = 0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    cout << "\nFinal Matrix:    \n";
    printMatrix(matrix, n, n);

}


int main(){
    vector<vector<int> > matrix = {
        {0, 98, 87, 3},
        {14, 53, 1, 6},
        {61, 88, 0, 12},
        {42, 11, 9, 23}        
        };
        
    int m = matrix[0].size();
    int n = matrix.size();
    printMatrix(matrix, n, m);
    rotateBy90Deg(matrix);

    
    return 0;
}