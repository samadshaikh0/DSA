#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    // First verity of the problem where negative and positive numbers are equal

    // vector<int> rearrangeArray(vector<int> &arr){
    //     int n = arr.size();
    //     int positiveIndex = 0;
    //     int negetiveIndex = 1;
    //     vector<int> ans(n, 0);
    //     for(int i = 0;i<n;i++){
    //         if(arr[i] < 0){
    //             ans[negetiveIndex] = arr[i];
    //             negetiveIndex += 2;
    //         }
    //         else{
    //             ans[positiveIndex] = arr[i];
    //             positiveIndex += 2;
    //         }
    //     }
    //     return ans;
    // } 


    // Second verity or a follow up question where posive elements are not equal to the negetive elements


    vector<int> rearrangeArray(vector<int> &arr){
        int n = arr.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(arr[i] > 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }
        int i = 0,j=0;
        while(i < pos.size() && j < neg.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }

        while(i < pos.size()){
            ans.push_back(pos[i]);
            i++;
        }

        while(j < neg.size()){
            ans.push_back(neg[i]);
            j++;
        }
            
        return ans;
    }



};


int main(){
    Solution s1 = Solution();
    vector<int> arr = {3,1,-2,-5,2,-4,8,7,6,5,-1,23,-4,12,34};
    vector<int> arr2 = {7, -2  -5, -3, -9, 6, -10, -8, -1, -4};
    vector<int> ans = s1.rearrangeArray(arr2);
    for(int x:ans) cout << x << "   ";

    return 0;
}