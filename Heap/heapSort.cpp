#include "bits/stdc++.h"
using namespace std;

class heap {
    public:
    int arr[1000];
    int size;

    heap(){
        arr[0] = {-1};
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        arr[size] = val;
        int index = size; 
        
        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else    
                return ;
        }
    }

    void print(){
        for(int i = 1;i<=size;i++){
                cout << arr[i] << " ";
        }
    }


    void deleteNode(){ // root node is always deleted
        if(size == 0){
            cout << "No node is present to delete\n";
            return;
        }
        // step 1: copy the last element to the first place
        arr[1] = arr[size];
        size--;

        // step 2:
        int i = 1;
        while(i <= size){
            int left = 2*i;
            int right = 2*i + 1;

            if( left < size && arr[i] < arr[left]){
                swap(arr[left], arr[i]);
                i = left;
            }

            else if( right < size && arr[i] < arr[right]){
                swap(arr[right], arr[i]);
                i = right;
            }
            else    
                return ;
        }
    }
};


void heapify(int arr[], int n, int index) {
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    int size = n-1;
    while (size > 1) {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    int arr[] = {-1, 5, 8, 3, 12, 14, 7};
    int n = 7;  
    buildHeap(arr, n);

    for(int i = 1;i<n;i++)
        cout << arr[i] <<"   ";
    cout << endl;
    
    heapSort(arr, n);

    for(int i = 1;i<n;i++)
        cout << arr[i] <<"   ";

    
    return 0;
}