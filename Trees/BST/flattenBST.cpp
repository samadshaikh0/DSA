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
    
    inOrderTraversal(root->left,in);
    cout << root->data << " ";
    in.push_back(root->data);
    inOrderTraversal(root->right,in);
}





int main() {
    node* root = NULL;
    takeInput(root);
    vector<int> inorderVal;
    inOrderTraversal(root,inorderVal);
    node* newNode = new node(inorderVal[0]);
    int n = inorderVal.size();
    node* curr = newNode;
    
    
    for(int i = 1;i < n; i++){

        node* temp = new node(inorderVal[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }

    // Last Node
    curr->left = NULL;
    curr->right = NULL;
    vector<int> temporary_vector;

    inOrderTraversal(root,temporary_vector);
    return 0;
}
