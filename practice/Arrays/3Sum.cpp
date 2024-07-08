#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if( i>0 && nums[i]==nums[i-1] )
            {
                continue;
            }
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    v.push_back({nums[i],nums[j],nums[k]});
                    while( j<k && nums[k]==nums[k-1]) k--;
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                    k--;
                }
                else if(sum>0)
                {
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return v;
    }
};




int main(){


    return 0;
}