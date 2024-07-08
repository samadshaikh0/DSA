#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        // map<int,int> count;
        // vector<int> ans;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     count[nums[i]]++;
        //     if(count[nums[i]] > floor(n/3))
        //         ans.push_back(nums[i]);
            
        //     if(ans.size() == 2)
        //         break;
        // }
        // return ans;

        int n = arr.size();
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && el2 != arr[i]){
                el1 = arr[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && el1 != arr[i]){
                cnt2 = 1;
                el2 = arr[i];
            }
            else if(el1 == arr[i]) cnt1++;
            else if(el2 == arr[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        // Now perform manual checking on el1 and el2
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;

        for(int x:arr){
            if(el1 == x) cnt1++;
            else if(el2 == x) cnt2++;
        }
        if(cnt1 > floor(n/3))
            ans.push_back(el1);
            
        if(cnt2 > floor(n/3))
            ans.push_back(el2);

        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main(){

    return 0;
}