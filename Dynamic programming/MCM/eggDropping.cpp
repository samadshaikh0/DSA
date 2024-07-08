#include "bits/stdc++.h"
using namespace std;


int solve(int e, int f){
    if(f == 0 || f == 1)
        return f;
    if(e == 1)
        return f;

    int mini = INT_MAX;

    for(int k=1; k<=f; k++){
        int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
        mini = min(mini, temp);
    }

    return mini;
    
}
int t[1001][1001];
int memoization(int e, int f){
    // base case
    if(e == 1)
        return f;
    if(f == 0 || f == 1)
        return f;
    
    if(t[e][f] != -1)
        return t[e][f];
    
    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        int temp = 1 + max(memoization(e-1, k-1) , memoization(e, f-k)) ;
        ans = min(temp, ans);
    }
    return t[e][f] = ans;
}



int bottom_up_optimization(int e, int f){
    // base case
    if(e == 1)
        return f;
    if(f == 0 || f == 1)
        return f;
    
    if(t[e][f] != -1)
        return t[e][f];
    
    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        int egg_breaks = (t[e-1][k-1] != -1) ? t[e-1][k-1]: bottom_up_optimization(e-1, k-1);
        int egg_does_not_break = (t[e][f-k] != -1) ? t[e][f-k]: bottom_up_optimization(e, f-k);
        int temp = 1 + max(egg_breaks, egg_does_not_break);
        ans = min(temp, ans);
    }
    return t[e][f] = ans;
}


int main(){
    int f=5,e=3;
    cout << "recursive\t" << solve(e,f);
    memset(t, -1, sizeof(t));
    cout << "\nmemoization\t" << memoization(e,f);
    memset(t, -1, sizeof(t));
    cout << "\nOptimized\t" << bottom_up_optimization(e,f);
    return 0;
}