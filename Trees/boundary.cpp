#include "bits/stdc++.h"
using namespace std;
// #include "traversal.cpp"

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


void traverseLeft(node* root,vector<int> &ans){
    // base case
    if(!root)
        return ;

    // leaf node
    if(root->left == NULL && root->right == NULL)
        return ;

    ans.push_back(root->data);

    if(root->left)
        traverseLeft(root->left,ans);
    else 
        traverseLeft(root->right,ans);
}

void traverseLeaf(node* root,vector<int> &ans){
    // base case
    if(root == NULL)
        return ;
    
    if(root->left == NULL && root->right == NULL)
        ans.push_back(root->data);
    
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root,vector<int> &ans){

    // base case
    if(root == NULL)
        return ;
    
    if(root->left == NULL && root->right == NULL)
        return ;
    
    if(root->right)
        traverseRight(root->right,ans);
    else    
        traverseRight(root->left,ans);
    
    // returning from function call
    ans.push_back(root->data);
}




vector<int> boundary(node* root){
    vector<int> ans;
    if(!root)
        return ans;
    ans.push_back(root->data);

    // traverse left part
    traverseLeft(root->left,ans);

    // traverse leaf Nodes
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

    // traverse right prt
    traverseRight(root->right,ans);

    return ans;
}



int main(){

    node* root = NULL;
    root = buildTree(root);
    vector<int> result = boundary(root);
    for(auto x:result) cout<<x << " ";
    return 0;
}