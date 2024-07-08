#include "bits/stdc++.h"
using namespace std;


vector<int> subsetSum(int *arr, int sum,int n){
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

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++)
            t[i][j] = (arr[i-1] <= j) ? t[i-1][j - arr[i-1]] ||  t[i-1][j] : t[i-1][j]; 
    }

    // Space comp : O(N2)

    // below is the optimized code
    // bool t[sum + 1] = {false};
    // t[0] = true;

    // for (int i = 0; i < n; i++) {
    //     for (int j = sum; j >= arr[i]; j--) {
    //         t[j] = t[j] || t[j - arr[i]]; 
    //     }
    // }

    // space comp : O(N)

    vector<int> potential_candidates;
    for(int i=0; i<=sum; i++){
        if(t[n][i])
            potential_candidates.push_back(i);
    }
    return potential_candidates;
}


int minSubsetSumDifference(int *arr,int n){
    vector<int> potential_candidates;
    int sum = 0;
    for(int i=0;i<n;i++) sum += arr[i];
    potential_candidates = subsetSum(arr,(sum/2),n);
    int mini = INT_MAX;
    for(auto x:potential_candidates)
        mini = min(mini, sum - 2*x);
    return mini;
}




int main(){
    int arr[] = {1,6,11,5,1,4};
    int n = sizeof(arr)/sizeof(int); 
    int sum = 35;  
    cout << minSubsetSumDifference(arr,n);   
    return 0;  
}