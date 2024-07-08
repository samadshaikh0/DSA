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

// We could use any type of traversal that is level-order in-order, pre-order or post-order to calculate total number of beats nodes

void inorderTraversal(node* root,int &count){
    if(root == NULL)
        return ;

    inorderTraversal(root->left,count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inorderTraversal(root->right,count);

}


int main(){
    node* root = NULL;
    root = buildTree(root);
    int count = 0;
    inorderTraversal(root,count);
    cout << "Total count of the leaf nodes are: " << count;
    count = 0;
    return 0;
}

