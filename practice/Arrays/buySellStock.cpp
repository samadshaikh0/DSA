#include "bits/stdc++.h"
using namespace std;


class Solution {
public:

    int maxProfit(vector<int> &prices){
        int n = prices.size();
        int mini = prices[0];
        int profit = INT_MIN;
        for(int i = 0;i < n;i++){
            int cost = prices[i] - mini;
            
            profit = max(profit, cost);

            mini = min(prices[i], mini);
        }
        return profit;
    }



};


int main(){
    Solution s1 = Solution();
    vector<int> prices = {7,1,5,3,6,4};
    cout << s1.maxProfit(prices);
    return 0;
}