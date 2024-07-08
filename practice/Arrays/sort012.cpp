#include "bits/stdc++.h"
using namespace std;

// following algorithm is known as DNF algorithm Time complexity : O(N), Space complexity : O(1)
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int mid = 0;
        int low = 0;
        int high = arr.size() - 1;


        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }

            else if(arr[mid] == 1){
                mid++;
            }

            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};



int main(){
    Solution s1 = Solution();
    vector<int> arr = {0,1,1,2,1,0,0,1,2,2,2,0,1,0,0,1,2};
    for(auto x:arr) cout << x <<"   ";
    cout << "\n";
    s1.sortColors(arr);
    for(auto x:arr) cout << x <<"   ";
    return 0;
}