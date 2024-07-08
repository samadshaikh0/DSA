#include "bits/stdc++.h"
using namespace std;


int kthSmallestElement(vector<int> a, int n, int k){
    priority_queue<int> pq;
    for(int i = 0;i<k;i++){
        pq.push(a[i]);
    }

    for(int i = k;i<n;i++){
        if(a[i] < pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    return pq.top();
}


int main(){
    vector<int> a = {55, 53, 54, 52, 50};
    int k = 1;
    int n = a.size();
    cout << kthSmallestElement(a, n, k);

    return 0;
}