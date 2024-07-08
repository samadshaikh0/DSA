#include "bits/stdc++.h"
using namespace std;

void reverseQueue(queue<int> &q){

    if(q.empty()){
        return ;
    }
     
    int num = q.front();
    q.pop();
    reverseQueue(q);
    q.push(num);
}


int main(){
    queue<int> q;
    q.push(10);
    q.push(3);
    q.push(5);
    q.push(9);
    
    cout << endl;
    reverseQueue(q);
    while(!q.empty()){
        cout << q.front()<<"    ";
        q.pop();
    }
    return 0;
}