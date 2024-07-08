#include "bits/stdc++.h"
using namespace std;
// i/p->arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 1, 2}
// o/p-> 4 {1,2,3,4}

// Better Approach(Optimal when elemenst are repeated) -  time comp:O(NlogN), Space Comp: O(1)
// 1.Sort the array
// 2.Maintain largest Smaller element initialize with INT_MIN
// 3.iterate through the array check if curr element is largest_smaller + 1
// 3.if yes then update largest and increase the count
// 4. if not then counter = 0 update largest_small to current element




int betterApproach(int *arr, int n){
    // int n = sizeof(arr);
    sort(arr, arr + n);
    cout << n << endl;
    
    int lastSmall =  INT_MIN;
    int longest = INT_MIN;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if( arr[i] - 1 == lastSmall){
            cnt+=1;
            lastSmall = arr[i];
        }

        else if(lastSmall != arr[i]){
            cnt = 1;
            lastSmall = arr[i];
        }
        longest = max(cnt, longest);
    }
    return longest;
}







int main(){
    int arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 1, 2};
    int n = 15;
    // cout << betterApproach(arr, n);

    return 0;
}