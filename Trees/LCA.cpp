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


node* lca(node* root,int n1,int n2){
    // base case
    if(root == NULL)
        return NULL;
    
    if(root->data == n1 || root->data == n2)
        return root;

    node* leftAns = lca(root->left,n1,n2);

    node* rightAns = lca(root->right,n1,n2);

    // 4 permutations possible
    if(leftAns != NULL && rightAns != NULL)
        return root;

    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;

    else 
        return NULL;
} 

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout << "Common ancestor of 61 and 2 is:   " << lca(root,2,61)->data;

    // 1 2 6 -1 -1 8 15 18 -1 61 -1 -1 23 -1 -1 -1 3 5 -1 -1 9 10 -1 -1 -1




}