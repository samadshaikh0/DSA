#include "bits/stdc++.h"
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start < end) {
        if (s[start] != s[end]) {
            return false;    
        } else {
            start++;
            end--;
        }
    }
    
    return true;
}

int solve(string s, int i, int j){
    // base case
    if((i >= j) || isPalindrome(s, i, j)){
        return 0;
    }
    int mini = INT_MAX; 
    for(int k=i; k<j; k++){
        int temp = 1 + solve(s, i, k) + solve(s, k+1 ,j);
        mini = min(mini, temp);
    }

    return mini;
}

int main(){
    string s = "";
    int n = s.size() - 1;
    cout << solve(s, 0, n);
}