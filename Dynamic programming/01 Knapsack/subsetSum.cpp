#include "bits/stdc++.h"
using namespace std;

bool solve(int *arr, int n, int sum){
    bool t[n+1][sum+1];

    // initialization
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }

    // similiarity with 0/1 knapsack
    // weight[] = arr[]
    // W = sum
    // value[] = X(ignored)

    // next step
    // converting 0/1 knapsack code 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main(){

    int arr[] = {2,3,7,8,10};
    int sum = 22;
    int n = sizeof(arr)/sizeof(int);
    if(solve(arr,n,sum))
        cout << "sum : " << sum << " is possible";
    else
        cout << "Not possible";
    return 0;
}