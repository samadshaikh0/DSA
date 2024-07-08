#include "bits/stdc++.h"
using namespace std;

void reverseKElements(queue<int>& q, int n, int k) {
  // Base case: No elements to reverse
  if (k == 0) {
    return;
  }

  // Move the first element to the back of the queue
  int firstElement = q.front();
  q.pop();

  // Recursively reverse the remaining (n-1) elements
  reverseKElements(q, n - 1, k - 1);

  // Push the first element back to the front of the queue
  q.push(firstElement);

  // Reverse the remaining (n-k) elements
  for (int i = 0; i < n - k; i++) {
    int element = q.front();
    q.pop();
    q.push(element);
  }
}



int main(){
    queue<int> q;
    q.push(9);
    q.push(21);
    q.push(89);
    q.push(92);
    q.push(91);
    q.push(46);
    reverseKElements(q,q.size(),5);
    while(!q.empty()){
        cout << q.front()<<"    ";
        q.pop();
    }
    return 0;
}