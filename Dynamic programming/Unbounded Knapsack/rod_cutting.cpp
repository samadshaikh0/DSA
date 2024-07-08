#include <bits/stdc++.h>
using namespace std;

int rod_cutting(int *price, int n, int cuts) {
    int t[n+1][cuts+1];

    // Initialization of table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cuts; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            } else {
                t[i][j] = (j >= i) ? max(t[i][j - i] + price[i-1], t[i-1][j]) : t[i-1][j];
            }
        }
    }
    return t[n][cuts];
}

int main(){
    int price[] = {2,5,7,8,10};
    int n = sizeof(price) / sizeof(int);
    int cuts = 7;
    cout << rod_cutting(price, n, cuts);

    return 0;
}
