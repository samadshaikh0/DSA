#include "bits/stdc++.h"
using namespace std;



int solve(string s,int i, int j, bool isTrue){
    // base case
    if(i > j)
        return false;
    if(i == j){
        if(isTrue)  
            return s[i] == 'T';   //it will evaluato 1 or 0
        else 
            return s[i] == 'F';  //it will evaluato 1 or 0
    }
    
    int ans = 0;

    for(int k=i+1; k<j; k+=2){
        int leftT = solve(s,i,k-1, true);
        int leftF = solve(s, i, k-1, false);
        int rightT = solve(s, k+1, j, true);
        int rightF = solve(s, k+1, j, false);

        if(s[k] == '&'){
            if(isTrue)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF + leftF * rightT;
        }

        else if(s[k] == '|'){
            if(isTrue)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans += leftF * rightF;
        }

        else{
            if(isTrue){
                ans += leftT * rightF + leftF * rightT;
            }
            else
                ans += leftF * rightF + leftT * rightT;
        }
    }
    return ans;
}

unordered_map<string, int> mpp;
int memoization(string s, int i, int j, bool isTrue){

    // base case
    if(i > j)
        return false;
    if(i == j){
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    // if value is already present
    string temp = to_string(i) + ' ' + to_string(j) + ' ' + to_string(isTrue);
    if(mpp[temp])
        return mpp[temp];
    
    int ans = 0;
    for(int k=i+1; k<j; k+=2){
        int leftT = solve(s, i, k-1, true); 
        int leftF = solve(s, i, k-1, false);
        int rightT = solve(s, k+1, j, true);
        int rightF = solve(s, k+1, j, false);
        
        if(s[k] == '&'){
            if(isTrue)
                ans += leftT * rightT;
            else
                ans +=  leftT * rightF +  leftF * rightT +  leftF * rightF;
        }
        else if(s[k] == '|'){
            if(isTrue)
                ans += leftT * rightF +  leftF * rightT +  leftT * rightT;
            else
                ans += leftF * rightF;
        }
        else{
            if(isTrue)
                ans += leftT * rightF + leftF * rightT;
            else
                ans += leftF * rightF + leftT * rightT;
        }
    }
    return mpp[temp] = ans;
}

int main(){
    string s = "T|T&F^T"; 
    int n = s.size() - 1;
    cout << memoization(s,0,n,true);
    return 0;
}
