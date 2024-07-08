#include "bits/stdc++.h"
using namespace std;


bool subSetSum(int *arr,int n,int sum){
    bool t[n+1][sum+1];

    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }


    // converting choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j - arr[i-1]]  || t[i-1][j];
            
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}



bool equalSumPartition(int *arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    
    if(sum%2 == 0)
        return subSetSum(arr,n,(sum/2));

    // if sum is odd we can never have equal some partition

    return false;
}


int main(){

    int arr[] = {1,12,4,5};
    int n = sizeof(arr)/sizeof(int);   
    cout << (float)equalSumPartition(arr,n);   
    return 0;
}