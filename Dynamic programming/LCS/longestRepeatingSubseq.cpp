#include "bits/stdc++.h"
using namespace std;

int solve(int n, int m, string s1, string s2){
    int t[n+1][m+1];

    // initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if( (s1[i-1] == s2[j-1]) && (i != j) ){
                t[i][j] = 1 + t[i-1][j-1];
                
            }
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][m];
}

int main(){
    string str1 = "AXABEBCDFD";
    string str2(str1);
    int n = str1.size();
    int m = str2.size();
    
    cout << "longest repeating subsequence : " << solve(n,m,str1, str2);
    return 0;
}