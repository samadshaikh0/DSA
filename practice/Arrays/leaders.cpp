#include "bits/stdc++.h"
using namespace std;

vector<int> leaders(int arr[], int n){
    vector<int> ans;
    int maxi = INT_MIN;
    
    for(int i = n-1; i>=0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    // leaders();
    return 0;
}