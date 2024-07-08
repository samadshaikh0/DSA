#include "bits/stdc++.h"
using namespace std;

int unbounded_knapsack(int *weight,int *value,int capacity ,int n){
    int t[n+1][capacity+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;  // If no items or zero capacity, maximum value is 0
            } else {
                if (weight[i - 1] <= j) {  // If current item's weight is less than or equal to capacity
                    t[i][j] = std::max(value[i - 1] + t[i][j - weight[i - 1]], t[i - 1][j]);
                    // Include current item or exclude it (whichever yields higher value)
                } else {
                    t[i][j] = t[i - 1][j];  // Exclude current item if it exceeds capacity
                }
            }
        }
    }
    return t[n][capacity];
}


int main(){
    
    int weight[] = {1,3,4};
    int value[] = {10,40,50};
    int capacity = 6;
    cout << unbounded_knapsack(weight,value,capacity,3);
    return 0;
}