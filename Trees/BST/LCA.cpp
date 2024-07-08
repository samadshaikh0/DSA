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


void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
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


node* LCA(node* root,int p,int q){
    // base case
    if( root == NULL)
        return NULL;
    
    if(root->data > p && root->data > q){
        return LCA(root->left,p,q);
    }

    if(root->data < p && root->data < q){
        return LCA(root->right,p,q);
    }

    return root;
}

int main() {
    node* root = NULL;
    takeInput(root);
    inOrderTraversal(root);
    int lowest_Common_ancestor = LCA(root,5,90)->data;
    cout<< "\n" << lowest_Common_ancestor << endl;
    return 0;
}
