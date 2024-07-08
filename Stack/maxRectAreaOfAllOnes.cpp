#include "bits/stdc++.h"
using namespace std;

vector<int> nextSmallerEl(vector<int> &arr, int n) {
    stack<int> s;
    s.push(n);  // Changed -1 to n
    vector<int> ans(n, -1);  // Initialize ans with -1
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while ((s.top() != n) && (arr[s.top()] >= curr)) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerEl(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n, -1);  // Initialize ans with -1
    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        while ((s.top() != -1) && (arr[s.top()] >= curr)) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int maxRectangleAreaInHistogram(vector<int> &arr, int n) {
    vector<int> next = nextSmallerEl(arr, n);
    vector<int> prev = prevSmallerEl(arr, n);
    int area = INT_MIN;

    for (int i = 0; i < n; i++) {
        int l = arr[i];
        if (next[i] == n) {  // Changed -1 to n
            next[i] = n - 1;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;

        area = max(area, newArea);
    }
    return area;
}

// int row;
int maxRectAreaOFAllOnes(vector<vector<int>> &M,int n,int m){
    int area = maxRectangleAreaInHistogram(M[0],m); //getting area of first row

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]!=0)
                M[i][j] = M[i][j]+M[i-1][j];
            else 
                M[i][j] = 0;
        }
        // all rows updated
        area = max(area,maxRectangleAreaInHistogram(M[i],m));
    }
    return area;
}



int main(){
    vector<vector<int>> 
    M = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
    int rows = M.size()/M[0].size();
    int cols = sizeof(M[0])/sizeof(int);
    cout << maxRectAreaOFAllOnes(M,4,4) <<endl;
    return 0;
}