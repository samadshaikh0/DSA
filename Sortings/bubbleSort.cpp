#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>& arr, int n)
{  
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}

int main() {
  vector<int> n = {3,4,2,1,6,4,7,9,4};
  int size = n.size();

  BubbleSort(n,size);

  for(auto x:n){
    cout << x << "  ";
  }

  return 0;
}