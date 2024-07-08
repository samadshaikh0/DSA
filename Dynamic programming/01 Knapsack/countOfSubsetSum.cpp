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




int main(){
    int arr[] = {1,2,3,5,6,8,10};
    int n = sizeof(arr)/sizeof(int); 
    int sum = 35;  
    cout << countSubSetSum(arr,n, sum);   
    return 0;  
}