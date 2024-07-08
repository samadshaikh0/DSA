#include <bits/stdc++.h>
using namespace std;

int coin_change_1(int *coins, int n, int sum) {
    int t[n+1][sum+1];

    // Initialization of table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (i == 0) {
                t[i][j] = 0;
            } 
            else if (j == 0){
                t[i][j] = 1;
            }
            else{
                t[i][j] = (j >= coins[i-1]) ? t[i][j-coins[i-1]] + t[i-1][j] : t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int coin[] = {1,2,3};
    int n = sizeof(coin) / sizeof(int);
    int sum = 5;
    cout << coin_change_1(coin, n, sum) << endl;
    return 0;
}
