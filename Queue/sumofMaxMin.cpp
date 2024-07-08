#include "bits/stdc++.h"
using namespace std;

int solve(int *arr,int n,int k){
    deque<int> maxi;
    deque<int> mini;

    // Addition of first size k window
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;

    for(int i = k;i<n;i++){
        ans += arr[maxi.front()] + arr[mini.front()];

        // Next window

        // Removal
        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        
        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    
    ans+= arr[maxi.front()] + arr[mini.front()];

    return ans;
}



int main(){
    int arr[] = {2,5,-1,7};
    cout << solve(arr, 4, 2);
    return 0;
}