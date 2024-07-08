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


void flatten(node* &root){
    node* curr = root;

    while(curr != NULL){
        if(curr->left){
            node* pred = curr->left;
            while(pred->right != NULL)
                pred = pred->right;
            
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }

}
int main(){
    node* root = NULL;
    root = buildTree(root);
    flatten(root);
    inOrderTraversal(root);




    // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1 
}