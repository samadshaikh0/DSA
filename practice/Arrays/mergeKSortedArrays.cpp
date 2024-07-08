#include "bits/stdc++.h"
using namespace std;

class node {
    public:
        int data;
        int i;
        int j;

        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
};


class compare {
    public:
        bool operator()(node* a,node* b)
            {return a->data > b->data;} 
};


vector<int> mergeKSortedArrays(vector<vector<int> > &Arrays, int k){
    
    priority_queue<node*, vector<node*>, compare > minHeap;
    // step 1 - insert 1st elements of all k arrays in heap

    for(int i = 0;i<k;i++){
        node* temp = new node(Arrays[i][0], i, 0);
        minHeap.push(temp);
    } 

    vector<int> ans;
    while(!minHeap.empty()){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        // extracting array with i,j

        int i = temp->i;
        int j = temp->j;

        j++;
        if(j < Arrays[i].size()){
            node* next = new node(Arrays[i][j], i, j);
            minHeap.push(next);
        }
    }

    return ans;
} 













int main(){
    vector<vector<int>> kArrays ={
        {5,6,7},
        {1,2,5},
        {8,9,10}
    };
    int k = 3;
    vector<int> ans = mergeKSortedArrays(kArrays,k);
    for(auto y:ans) cout << y << "  ";
    
    return 0;
}