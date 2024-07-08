#include "bits/stdc++.h"
using namespace std;

// Approach:
// 1. Brute force-sort the array and traverse from last to first and return ans -O(n2)
// 2. a.traverse through the array and find largest
//    b.initialize second largest = INT_MIN
//    c.traverse throught the array if current element is less than largest and greater than second largest
//    d.return second largest 


int secondLargest(vector<int> &arr, int n){
    int LargestElement = INT_MIN;
    int sLargest = INT_MIN;
    
    for(int i = 0;i<n;i++){
        if(arr[i] > LargestElement){
            sLargest = LargestElement;
            LargestElement = arr[i];
        }
        else if(arr[i] < LargestElement && arr[i] > sLargest){
            sLargest = arr[i];
        }
    }
    
    return sLargest;
    
}

int secondSmallest(vector<int> &arr, int n){
    int smallestElement = INT_MAX;
    int sSmallest = INT_MAX;
    
    for(int i = 0;i<n;i++){
        if(arr[i] < smallestElement){
            sSmallest = smallestElement;
            smallestElement = arr[i];
        }
        else if(arr[i] > smallestElement && arr[i] < sSmallest){
            sSmallest = arr[i];
        }
    }
    
    return sSmallest;
}


int main(){
    vector<int> arr = {1,2,4,7,7,6,8,8,3,1,2,9,10};
    int n = arr.size();
    cout << secondLargest(arr,n) << endl;
    cout << secondSmallest(arr,n);


    


    return 0;

}