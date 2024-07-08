#include "bits/stdc++.h"
using namespace std;

int lcs_rec(int n, int m, string s1, string s2){
    
    // base case
    if(n == 0 || m == 0)
        return 0;

    else if(s1[n] == s2[m])
        return 1 + lcs_rec(n-1,m-1,s1,s2);
    
    return max(lcs_rec(n-1,m,s1,s2), lcs_rec(n,m-1,s1,s2));
}


int lcs_memo(int n, int m, string s1, string s2, int **t){
    // base case
    if(n == 0 || m == 0)
        return 0;
    
    else if(t[n][m] != -1)
        return t[n][m]; 
    
    else if(s1[n] == s2[m])
        return t[n][m] = 1 + lcs_memo(n-1,m-1,s1,s2,t);
    
    return t[n][m] = max(lcs_memo(n-1,m,s1,s2,t), lcs_memo(n, m-1, s1,s2,t));
}

int lcs_bottom_up(int n, int m, string s1, string s2){
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
    string str1 = "notgxy";
    string str2 = "notanewguy";
    int n = str1.size();
    int m = str2.size();
    int **t = new int*[n+1];

    for(int i=0; i<=n; i++){
        t[i] = new int[m+1];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            t[i][j] = -1;
        }
    }

    cout << "Recursion : " << lcs_rec(n, m, str1, str2);
    cout << "\nMemoization : " << lcs_memo(n, m, str1, str2, t);
    cout << "\nBottom Up : " << lcs_bottom_up(n,m,str1, str2);
    return 0;
}