#include "bits/stdc++.h"
using namespace std;


string solve(string s1, string s2, int n, int m){
    int t[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = (s1[i-1] == s2[j-1]) ? 1 + t[i-1][j-1]: max(t[i-1][j], t[i][j-1]);
        }
    }

    int i=n,j=m;
    string ans = "";

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(t[i][j-1] > t[i-1][j]){
            // store the value
            ans.push_back(s2[j-1]);
            j--;
        }
        else{
            ans.push_back(s1[i-1]);
            i--;
        }
    }

    // if we reach end of the second string that is j == 0
    while(i > 0){
        ans.push_back(s1[i-1]);
        i--;
    } 
    // if we reach end of the first string that is i == 0
    while(j > 0){
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";

}


int main(){
    string s1 = "acbcf";
    string s2 = "abcdaf";
    int n = s1.size();
    int m = s2.size();
    solve(s1, s2, n, m);
    
    return 0;
}