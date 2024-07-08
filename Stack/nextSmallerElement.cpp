#include "bits/stdc++.h"
using namespace std;

vector<int> findNextMinElement(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans;

    for(int i = n-1;i>=0;i--){
        int curr = arr[i];

        while((!s.empty()) && (s.top()>=curr)){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector <int> v1 = {2,1,4,7,3,9};
    vector<int>  ans = findNextMinElement(v1,6);
    for(auto x:ans){
        cout << x <<" ";
    }
    return 0;
}