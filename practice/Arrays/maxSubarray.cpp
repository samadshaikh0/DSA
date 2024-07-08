#include "bits/stdc++.h"
using namespace std;


// Brute force approach
// void maxSubArray(vector<int> &arr){
//     int n = arr.size();
//     int maxSum = INT_MIN;

//     for(int i = 0;i<n;i++){
//         for(int j = i;j<n;j++){
//             int sum = 0;
//             for(int k = i;k<=j;k++){
//                 sum += arr[k];
//             }
//             maxSum = max(sum, maxSum);
//         }
//     }
//     cout << maxSum;
// }

class Solution {
public:
    // Kadane's Algorithm
    pair<vector<int>, int> maxSubArray(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int maxi = INT_MIN;

        int ansStart = -1;
        int ansEnd = -1;
        int start = 0;

        for(int i = 0;i < n;i++){
            if(sum == 0){
                start = i;
            }

            sum += arr[i];
            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0)
                sum = 0;
        }
        vector<int> ans;
        for(int i = ansStart ;i <= ansEnd; i++){
            ans.push_back(arr[i]);
        }

        return make_pair(ans,maxi);
    }

};




int main(){
    Solution s1 = Solution();
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    // pair<vector<int>, int> p = s1.maxSubArray(arr);
    // cout<< "Maximum Sub array:  "<<endl;

    // for(auto x:p.first){
    //     cout << x <<"   ";
    // }

    // cout << "Maximum Sum:   " << p.second;
    maxSubArray(arr);
    return 0;
}