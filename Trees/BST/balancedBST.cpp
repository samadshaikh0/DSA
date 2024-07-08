#include <bits/stdc++.h>
#include <vector>

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

node* insertIntoBST(node* &root,int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data)
        root->right = insertIntoBST(root->right,data);


    else if(data < root->data)
        root->left = insertIntoBST(root->left,data);

    return root;
}


void takeInput(node* &root){
    int data;
    cout << "Enter data: ";
    cin >> data;

    while(data != -1){
        insertIntoBST(root,data);
        cout << "Enter data: ";
        cin >> data;
    }
}


void inOrderTraversal(node* root,vector<int> &in){
    if(root == NULL){
        return;
    }
    
    inOrderTraversal(root->left, in);
    // cout << root->data << " ";
    in.push_back(root->data);
    inOrderTraversal(root->right,in);
}


node* balancedBST(vector<int> &in, int s,int e){
    if( s > e)
        return NULL;
    
    int mid = s + (e-s)/2;
    node* root = new node(in[mid]);
    root->left = balancedBST(in,s,mid-1);
    root->right = balancedBST(in,mid+1,e);

    return root;

}




int main() {
    node* root = NULL;
    takeInput(root);
    vector<int> inorderVal;
    inOrderTraversal(root,inorderVal);
    int n = inorderVal.size();
    balancedBST(inorderVal,0,n);

    return 0;
}
