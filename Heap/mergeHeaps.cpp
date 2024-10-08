#include "bits/stdc++.h"
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}


int main(){
    vector<int> a = {55, 53, 54, 52, 50};
    vector<int> b = {3, 1, 5, 2, 4};

    vector<int> c;
    for(auto i:a)
        c.push_back(i);

    for(auto i:b)
        c.push_back(i);

    int n = c.size();
    cout << c.size();
    for(int i = n/2 - 1;i>=0;i--)