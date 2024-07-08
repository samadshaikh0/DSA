#include "bits/stdc++.h"
using namespace std;

// following algorithm is known as DNF algorithm Time complexity : O(N), Space complexity : O(1)
class Solution {
public:
    int majorityElement(vector<int> &arr){
        int n = arr.size();

        int element = arr[0];
        int vote = 1;
        // Moore's Algorithm
        for(int i = 1;i<n;i++){
            if(vote == 0){
                element = arr[i];
                vote = 1;
            }
            else if(arr[i] == element)
                vote++;
            else
                vote--;
        }

        // check whether the element is majority or not
        int counter = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] == element){
                counter++;
            }
        } 
        if(counter > n/2)
            return element;
        else    
            return -1;
    }
};

int main(){
    Solution s1 = Solution();
    vector<int> arr = {2,2,1,3,1,1,3,1,1};
    cout << "Majority Element is:   " << s1.majorityElement(arr); 
    return 0;
}