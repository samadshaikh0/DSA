#include "bits/stdc++.h"
using namespace std;

int solve(int n, int m, string s1, string s2){
    int t[n+1][m+1];
    int maxLeangth = INT_MIN;


    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                maxLeangth = max(maxLeangth, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return maxLeangth;
}

int main(){
    string str1 = "majorsubstringhasme";
    string str2 = "substring";
    int n = str1.size();
    int m = str2.size();
    
    cout << "longest common substring : " << solve(n,m,str1, str2);
    return 0;
}