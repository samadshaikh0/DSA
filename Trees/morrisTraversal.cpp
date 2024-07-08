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


void inOrderTraversal(node* root){
    //L-N-R

    // base condition
    if(root == NULL)
        return ;
    // 1.L
    inOrderTraversal(root->left);
    // 2.N
    cout << root->data <<" ";
    // 3.R
    inOrderTraversal(root->right);
    
}

void MorrisTraversal(node* root,vector<int> &ans){
    node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){

            ans.push_back(curr->data);
            curr = curr->right;

        }
        else{
            node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == curr){
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                pred->right = curr;
                curr = curr->left;
            }
        }
    }
    
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    vector<int> ans;

    cout << "Morris Traversal:  ";
    MorrisTraversal(root,ans);
    for(auto i:ans) 
        cout << i << " ";

    cout << "\nInorder traversal:  ";
    inOrderTraversal(root);

    // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1 
}