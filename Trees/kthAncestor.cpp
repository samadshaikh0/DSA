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


// void kthAncestor(node* root,int k,int Node,int &ans,vector<int> &path){

//     if(!root)
//         return ;
    
//     if(root->data == Node){
//         ans = path[path.size()-k];
//         return ;
//     }

//     path.push_back(root->data);
//     // LST
//     kthAncestor(root->left,k,Node,ans,path);

//     // RST
//     kthAncestor(root->right,k,Node,ans,path);

//     path.pop_back();
// }
// Time complexity - O(n) space complexity != O(1) since vector is used

int kthAncestor(node* root,int k,int Node,vector<int> &path){
    // base case
    if(!root)
        return -1;
    
    if(root->data == Node)
        return Node;
    
    int leftAns = kthAncestor(root->left,k,Node,path);

    int rightAns = kthAncestor(root->right,k,Node,path);

    
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    int k = 3;
    int Node = 9;
    int ans;
    vector<int> path;
    kthAncestor(root,k,Node,ans,path);
    cout << "the answer is  "<< ans << endl;
    // 1 -1 3 -1 9 -1 7 -1 8 -1 5 -1 -1 
    // 1 2 3 8 9 10 -1 -1 -1 -1 -1 4 -1 -1 -1
}