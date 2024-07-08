#include "bits/stdc++.h"
using namespace std;

void interleaveFirstHalf(queue<int> &q,int n){
    // cout <<"Hello";
    queue<int> newQ;
    for(int i=0;i<(n/2);i++){
        int val = q.front();
        newQ.push(val);
        q.pop();
    }
    // q = {15,16,17,18}
    // newQ = {11,12,13,14}

    while(!newQ.empty()){
        int val1 = newQ.front();
        q.push(val1);
        newQ.pop();
        int val2 = q.front();
        q.pop();
        q.push(val2);
    }
}





int main(){
    queue<int> q;
    for(int i=11;i<=20;i++){
        q.push(i);
    }
    
    interleaveFirstHalf(q,q.size());
    while(!q.empty()){
        cout << q.front() <<"   ";
        q.pop();
    }
    
    return 0;
}