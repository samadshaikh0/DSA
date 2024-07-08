#include "bits/stdc++.h"
using namespace std;

int celebrity(vector<vector<int>> &M,int n){
    stack<int> s;
    // step 1:
    for(int i=0;i<n;i++){
        s.push(1);
    }

    // step 2:
    while(s.size() > 1){
        int a = s.top();
            s.pop();
        
        int b = s.top();
            s.pop();

        if(M[a][b] == 1)
            s.push(b);
        else 
            s.push(a);
        
    }
    // step 3:
    int answer = s.top();
    int zeroCount = 0;
    for(int i=0;i<n;i++){
        if(M[answer][i] == 0)
            zeroCount++;
    }
    if(zeroCount != n){
        return -1;
    }
    
    int oneCount = 0;
    for(int i=0;i<n;i++){
        if(M[i][answer] == 1)
            oneCount++;
    }
    if(oneCount != n-1){
        return -1;
    }
    return answer;
}

int main(){
    vector<vector<int>> 
    M = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int n = 3;
    cout << celebrity(M,n) << endl;   
                            
    return 0;
}