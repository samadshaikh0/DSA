#include "bits/stdc++.h"
using namespace std;

int signum(int a, int b){
    if(a == b)  return 0;
    else if(a > b)  return 1;
    else if(a < b)  return -1;
}

void findMedian(int element, priority_queue<int, vector<int> > &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median){

    int size_diff = signum(maxHeap.size(), minHeap.size());
    switch (size_diff){
        case  0:
            // The sizes are equal
            if(element > median){
                minHeap.push(element);
                median = minHeap.top();
            }
            else{
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;
        
        case 1:  //max heap.size() > min heap.size()
            if(element > median){
                minHeap.push(element);
            }
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
            break;

        case -1:
            // maxheap.size() < minheap.size()
            if(element > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
            }
            else{
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
            break;
    }
}



int main(){
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    priority_queue<int, vector<int> > maxHeap; 
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median = 0;
    vector<int> ans;

    for(int i = 0;i<n;i++){
        findMedian(arr[i],maxHeap, minHeap, median);
        ans.push_back(median);
    } 

    for(int x:ans) cout << x << "    ";
    return 0;
}