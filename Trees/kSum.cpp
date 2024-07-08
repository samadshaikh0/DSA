#include "bits/stdc++.h"
using namespace std;


class node {
    public:
        int data;
        node* left;
        node* right;

        //constructor
        node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};


node* buildTree(node* &root){
    cout << "Enter Data: " <<endl;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout << "Enter data to insert to the left of  " << data <<"\n";
    root->left = buildTree(root->left);

    cout << "Enter data to insert to the right of  " << data <<"\n";
    root->right = buildTree(root->right);
    return root;
}


void kSum(node* root, int k, int &count, vector<int> path){
    // base case
    if(root == NULL)
        return;
    
    // insert the current node
    path.push_back(root->data);

    // left sub tree call
    kSum(root->left,k,count,path);

    //right Sub tree call
    kSum(root->right,k,count,path);
    
    // check if sum of data is equal to k
    int size = path.size();
    int sum = 0;
    for(int i = size-1;i>=0;i--){
        sum+=path[i];
        if(sum == k)
            count++;
    }

    // while returning to previous node remove the last element
    path.pop_back();
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    int k = 8;
    int count = 0;
    vector<int> path;

    kSum(root,k,count,path);
    cout << "Count :    " << count;

    // 1 2 6 -1 -1 8 15 18 -1 61 -1 -1 23 -1 -1 -1 3 5 -1 -1 9 10 -1 -1 -1




}