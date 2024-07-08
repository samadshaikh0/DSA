#include "bits/stdc++.h"
using namespace std;

class node {
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};


class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data; 
        }
};

class Solution {

public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int n = nums[0].size();
        priority_queue<node*, vector<node*>, compare> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0;i<k;i++){
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            minHeap.push(new node(nums[i][0], i, 0));
        }

        int start = mini;
        int end = maxi;

        while(!minHeap.empty()){
            node* top = minHeap.top();
            minHeap.pop();
            mini = min(mini, top->data);

            if(maxi - mini < start - end){
                start = mini;
                end = maxi;
            }

            if(top->col + 1 < n){
                maxi = max(maxi, nums[top->row][top->col + 1]);
                minHeap.push(new node(nums[top->row][top->col + 1], top->row, top->col + 1));
            }
            else{
                break;
            }
        }

        vector<int> ans = {start + 1, end};
        return ans;
    }
};


int main(){
    Solution s1 = Solution();
    vector<vector<int> > nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    cout << "k: "<<nums.size() << endl;
    cout << "n: "<<nums[0].size() << endl;
    vector<int> ans = s1.smallestRange(nums);

    for(auto x:ans) cout << x << "  ";
}