#include "bits/stdc++.h"
using namespace std;

string solve(int n, int m, string s1, string s2){
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

    int i = n; 
    int j = m;
    string ans = "";
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(t[i][j-1] > t[i-1][j]){
            j--;
        }
        else
            i--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string str1 = "acbcf";
    string str2 = "abcdaf";
    int n = str1.size();
    int m = str2.size();

    cout << solve(n,m,str1, str2);
    return 0;
}