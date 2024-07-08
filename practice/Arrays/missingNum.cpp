#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xor1 = 0;
        int xor2 = 0;

        for(int i = 0;i<n;i++){
            xor1 = xor1 ^ (i+1);
            xor2 = xor2 ^ arr[i];
        }

        int res = xor1 ^ xor2;
        return res;
    }
};


int main(){
    Solution s1 = Solution();
    vector<int> arr = {4,1,2,0};
    cout << s1.missingNumber(arr);
    
    return 0;
}

