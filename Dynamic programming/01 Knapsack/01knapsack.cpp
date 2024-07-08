#include "bits/stdc++.h"
using namespace std;

int recursive(int * weight, int *value, int n, int W){
    // base condition
    if(n == 0 || W == 0)
        return 0;

    // ko include karna hai
    else if(weight[n-1] <= W)
        return max((value[n-1] + recursive(weight, value, n-1, W - weight[n-1])), recursive(weight, value, n-1, W));
    
    else
        return recursive(weight, value, n-1, W);

    return -1;
}

int memoization(int * weight, int *value, int n, int W, int **t){

    // base case
    if(n == 0|| W == 0)
        return 0;

    else if(t[n][W] != -1)
        return t[n][W];
    
    else if(weight[n-1] <= W)
        return max(value[n-1] + memoization(weight, value, n-1, W - weight[n-1],t),memoization(weight,value,n-1,W,t));
    else
        return memoization(weight,value,n-1,W,t);
}

int bottomUpApproach(int *weight, int *value, int n, int W){
    int t[n+1][W+1];
    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;    
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(weight[i-1]<= j){
                t[i][j] = max((value[i-1] + t[i-1][j-weight[i-1]]), t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][W];
}


int main(){
    int weight[] = {1, 3, 4, 5};
    int value[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;
    int **t = new int*[n+1];
    // cout << recursive(weight, value, n, W);  9

    for(int i=0; i<W; i++)
        t[i] = new int[W+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            t[i][j] = -1;
        }
    }

    cout << memoization(weight, value, n, W, t);
    // cout << bottomUpApproach(weight, value, n, W);

    return 0;

}