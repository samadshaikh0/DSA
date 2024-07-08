#include "bits/stdc++.h"
using namespace std;


int main(){
    vector<int> arr = {1,1,0,1,1,1};
    int cnt = 0;
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        if(arr[i] ==  1)
            cnt++;
        else{
            maxi = max(maxi, cnt);
            cnt = 0;
        }
    }
    cout << cnt;
    return 0;
}