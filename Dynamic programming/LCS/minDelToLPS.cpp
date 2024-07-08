#include "bits/stdc++.h"
using namespace std;


int LPS(string s1, int n){
    int m = n;
    string s2(s1);
    reverse(s2.begin(), s2.end());

    int t[n][m];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = (s1[i-1] == s2[j-1]) ? 1 + t[i-1][j-1] : max(t[i-1][j], t[i][j-1]);
        }

    }
    return n - t[n][m];
}   

int main(){
    string s = "agbcba";
    int n = s.size();
    cout << LPS(s,n);
    return 0;
}