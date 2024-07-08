// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;


// first minimum is placed at its correct position
void selection_sort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        int mini = i;
        for(int j=i; j<n; j++){
            mini = min(mini,arr[i]);
        }
        swap(arr[i],arr[mini]);
    }
}
// best case, worst case, avg case - O(N2) 


// place the largest element to its correct place
void bubble_sort(vector<int> &arr, int n){
    bool swapped = false;
    for(int i=0; i<n ; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
                swapped = true;
            } 
        }
        if(!swapped) break;
    }
}
// best case - O(N), worst case, avg case - O(N2)


void insertion_sort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int j=i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
} 


// best case - O(N2), worst case, avg case - O(N2)

int main() {
    vector<int> arr;
    int n = 10;

    for(int i=0; i<n; i++){
        int el;
        cin >> el;
        arr.push_back(el);
        cout << el << " ";
    }
    
    insertion_sort(arr, n);
    cout << endl;
    for(auto x:arr) cout << x << "  ";

  
    return 0;
}