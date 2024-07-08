#include "bits/stdc++.h"
using namespace std;




void print(vector<int> arr){
    for(auto x:arr) cout << x << "  ";
    cout << endl;
}

void solve(vector<int> &arr,int n,int k){

    int temp[n];
    int j = 0;
    for(int i = n-k;i<n;i++){
        temp[j++] = arr[i];
    }

    
    for(int i = 0;i<n-k;i++){
        arr[n-i-1] = arr[n-k-i-1];
    }

    for(int i = 0;i<n-k;i++){
        arr[i] = temp[i];
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    int k = 3;
    int temp[n];
    int j = 0;
    print(arr);
    

    
    print(arr);
    return 0;

}