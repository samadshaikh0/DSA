#include "bits/stdc++.h"
using namespace std;

// Approach:
// 1. Brute force-sort the array and traverse from last to first and return ans -O(n2)
// 2. a.traverse through the array and find largest
//    b.initialize second largest = INT_MIN
//    c.traverse throught the array if current element is less than largest and greater than second largest
//    d.return second largest 


int removeDuplicateArray(vector<int> &arr,int n){
    int j = 0; 
    for(int i = 0;i<n-1;i++){
        if(arr[i] != arr[i+1]){
            j++;
            arr[j] = arr[i+1];
        }
    }
    return j;
}




int main(){
    vector<int> arr = {1,2,4,7,7,2,6,8,8,3,1,2,9,10};
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(auto x:arr) cout << x << "  ";
    cout << "\n";
    int var = removeDuplicateArray(arr,n);
    for(auto x:arr) cout << x << "  ";
    cout << '\n';
    cout << "index :    " << var;

    


    return 0;

}