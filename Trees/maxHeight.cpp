#include "bits/stdc++.h"
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

        node(int val){
            this->data = val;
            this->right = NULL;
            this->left = NULL;
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

int maxHeight(node* root){
    if(root == NULL)
        return 0;
    return max(maxHeight(root->left),maxHeight(root->right))+1;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout << "Max height of the tree is " <<maxHeight(root);
    return 0;
}

