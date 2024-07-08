#include "bits/stdc++.h"
using namespace std;


int solve(string s1, int n){
    string str(s1);
    reverse(str.begin(), str.end());
    string s2 = str;
    int m = n;

    int t[n+1][m+1];
    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else{
                t[i][j] = (s1[i-1] == s2[j-1]) ? t[i][j] = 1 + t[i-1][j-1] : max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[n][m];
}

int main(){
    string str1 = "agbcba";
    int n = str1.size();
    cout  << "\n" << solve(str1, n);
    return 0;
}