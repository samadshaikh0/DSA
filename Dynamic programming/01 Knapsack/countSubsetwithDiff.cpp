#include "bits/stdc++.h"
using namespace std;


int countSubSetSum(int *arr,int n,int sum){
    int t[n+1][sum+1];

    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0)  //No elements in the array hence we cant have any subset 
                t[i][j] = 0;
            if(j == 0)   // We always have 1 subset(empty {}) which results in sum = 0
                t[i][j] = 1;
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j - arr[i-1]]  + t[i-1][j];     //replacing "||" with "+" we want the subsets by including and excluding arr[i-1]
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}


int countSubsetwithDiff(int *arr, int n, int diff){
    int sum = (diff + accumulate(arr, arr+n,0)) / 2;
    return countSubSetSum(arr,n,sum);
}

int main(){
    int arr[] = {1,2,1,3};
    int diff = 1;
    int n = sizeof(arr)/sizeof(int);
    cout << countSubsetwithDiff(arr,n,diff);

    return 0;
}