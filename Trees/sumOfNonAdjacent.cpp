#include "bits/stdc++.h"
using namespace std;

class node {
    public :
        int data;
        node*left;
        node*right;

        node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildTree(node* root){
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

pair<int,int> maximumSumOfNonAdjacent(node* root){

    if(!root){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = maximumSumOfNonAdjacent(root->left);
    pair<int,int> right = maximumSumOfNonAdjacent(root->right);

    pair<int,int> result; 
    result.first = root->data + left.second + right.second;
    result.second = max(left.first,left.second) + max(right.second,right.first);

    return result;

}



int main(){
    node* root = NULL;
    root = buildTree(root);
    pair<int,int> ans = maximumSumOfNonAdjacent(root);
    int answer = max(ans.first,ans.second);
    cout << "Answer:  " << answer;
    // 1 -1 3 -1 9 -1 7 -1 8 -1 5 -1 -1 
    // 1 2 3 8 9 10 -1 -1 -1 -1 -1 4 -1 -1 -1
}