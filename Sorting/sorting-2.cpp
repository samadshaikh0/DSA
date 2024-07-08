#include <bits/stdc++.h>
using namespace std;


/*
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half 
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

*/
// best case,worst case, avg case - O(NlogN)
// space complexity - O(N)


/*
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low; 
    int j = high;

    while(i < j) {
        while(i<=high && arr[i] <= pivot)
            i++;
        while(j>=low && arr[j] > pivot )
            j--;
            
        if(i < j) 
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qs(arr,low,pIndex-1);
        qs(arr, pIndex+1, high);
    }
}

*/


int main() {

    vector<int> arr = {3 ,8 ,12 ,4 ,75 ,3 ,19 ,84 ,31 ,85 ,10}  ;
    int n = arr.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    // qs(arr, 0, n-1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }

    return 0 ;
}