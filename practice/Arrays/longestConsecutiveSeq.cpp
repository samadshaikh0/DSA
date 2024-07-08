#include "bits/stdc++.h"
using namespace std;
// i/p->arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 1, 2}
// o/p-> 4 {1,2,3,4}

// Better Approach(Optimal when elemenst are repeated) - 
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




// Optimal Solution(If and only if elements are not repeating)-Time complexity : O(2N)
// Step 1-Put everything into the "unordered_set" data structure 
// Consider an example where after putthing elements into the set you are getting  "101" 
    // You should not directly try to find next integer that is 102 rather find "100"
    // if you donot find one prior integer then current element is probably a starting point
    // Start searching for the elements next to the current element and increase count in each iteration



int optimalApproach(int *arr, int n){
    if(n == 0)
        return 0;
    
    int largest = INT_MIN;

    unordered_set<int> st;

    for(int i = 0;i<n;i++)
        st.insert(arr[i]);
    
    
    for(auto x:st){
        if(st.find(x - 1) == st.end() ){
            int cnt = 1;
            int el = x;

            while(st.find(el + 1) != st.end()){
                el = el + 1;
                cnt += 1;
            }
            largest = max(cnt, largest);
        }
    }
    return largest;

}

int main(){
    // int arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 1, 2};
    // int n = 15;
    // cout << betterApproach(arr, n);

    int arr2[] = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int n2 = sizeof(arr2)/sizeof(int);
    cout << optimalApproach(arr2, n2);

    return 0;
}