#include "bits/stdc++.h"
using namespace std;

void solve(string s1, string s2, int n, int m){
    int t[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){

            if(i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = (s1[i-1] == s2[j-1]) ? 1+t[i-1][j-1] : max(t[i-1][j], t[i][j-1]);
        }
    }
    int lcsLength = t[n][m];
    int deletions = n - lcsLength;
    int insertions = m - lcsLength;

    cout << "Insertions : " << insertions << endl;
    cout << "Deletions : " << deletions;

}


int main(){
    string s1 = "heap";
    string s2 = "pea";
    int n = s1.length();
    int m = s2.length();
    solve(s1, s2, n, m);
    return 0;
}