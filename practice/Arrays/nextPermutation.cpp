#include "bits/stdc++.h"
using namespace std;


vector<int> nextPermutation(vector<int> &arr){
    int index = -1;
    int n = arr.size();
    
    for(int i = n-2;i>= 0;i--){
        if(arr[i] < arr[i+1] ){
            index = i;
            break;   
        }
    }

    if(index == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i = n-1; i>index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main(){
    vector<int> arr = {2,1,4,5,3,0,0};
    vector<int> ans = nextPermutation(arr);
    for(auto x:ans) cout << x << "  ";
    
    return 0;


}