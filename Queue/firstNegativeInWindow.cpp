#include "bits/stdc++.h"
using namespace std;


vector<int> firstNegativeInt(int *arr,int n,int k){
    queue<int> dq;
    vector<int> ans;

    // Step 1:
    for(int i=0;i<k;i++){
        if(arr[i] < 0)
        dq.push(i);
    }

    // Edge-case if size of dq is 0
    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }
    else {
        ans.push_back(0);
    }

    // Step 2: For remaining array

    for(int i=k;i<n;i++){

        if(i - dq.front()>=k)
            dq.pop();
        if(arr[i] < 0)
            dq.push(i);
        
        if(dq.size()==0){
            ans.push_back(0);
        }
        else {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}


int main(){
    int size;
    cin >> size;
    int arr[size];

    for(int i = 0;i<size;i++){
        cin >> arr[i];
    }
    int k;
    cout <<"K value:    ";
    cin >> k;
    vector<int> ans = firstNegativeInt(arr,size,k);
    for(auto x:ans) cout << x <<"   ";
    return 0;
}