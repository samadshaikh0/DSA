#include "bits/stdc++.h"
using namespace std;


class Solution {
public:

    int searchInsert(vector<int>& arr, int target) {

        int start = 0;
        int end = arr.size() - 1;
        int ans;
        while(start <= end){

            int mid = start + (end-start)/2;
            if(arr[mid] < target){
                start = mid + 1;
                ans = start;
            }
            else if(arr[mid] > target){
                end = mid - 1;
                ans = end + 1;
            }
            else{
                return mid;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}