#include "bits/stdc++.h"
using namespace std;


bool solve(string a, string b){
    if(a == b)
        return true;
    if(a.size() == 0)
        return true;
    if(a.size() <= 1 )
        return false;
    
    int n = a.size() - 1;
    bool flag = false;

    for(int i=1; i<n; i++){
        bool condition1 = solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i,n-i), b.substr(0,n-i));
        bool condition2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i,n-i), b.substr(i,n-i));

        if(condition1 || condition2){
            flag = true;
            break;
        }
    }
    return flag;
}


unordered_map<string, bool> mpp;
bool memoization(string a, string b){
    if(a == b)
        return true;
    if(a.size() <= 1)
        return false;
    
    string key = a + ' ' + b;
    if(mpp.find(key) != mpp.end())
        return mpp[key];
    int n = a.size() - 1;
    bool flag = false;

    for(int i=1; i<n; i++){
        bool condition1 = solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i,n-i), b.substr(0,n-i));
        bool condition2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i,n-i), b.substr(i,n-i));

        if(condition1 || condition2){
            flag = true;
            break;
        }
    }
    return mpp[key] = flag;

}





int main(){
    string a = "great"; 
    string b = "rgeat";
    if(a.size() != b.size())
        cout << "0" << endl;
    if(a.empty() || b.empty())
        cout << "0";
    cout << memoization(a, b);
    return 0;
}