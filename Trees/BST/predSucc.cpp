
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


pair<int,int> predSucc(node* root, int key){
    if(root == NULL){
        pair<int,int> p = make_pair(root->data,root->data);
        return p; 
    }

    node* temp = root;
    int succ = -1;
    int pred = -1;

    // Finding Node
    while(temp->data != key){

        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    //pred and succ

    // pred
    node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->left;
    }

    node* rightTree = temp->right;
    // Succ
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->right; 
    }

    pair<int,int> ans = make_pair(pred,succ);
    return ans;
}


int main() {
    node* root = NULL;
    takeInput(root);
    // 4 2 6 12 53 71 3 23 84 59 19 32
    inOrderTraversal(root);
    int key = 19;
    pair<int,int> ans = predSucc(root,key);
    cout << "\nPredecessor of "<< key << " is: "<< ans.first;
    cout << "\nSuccessor of "<< key << " is: "<< ans.second;    

    return 0;
}
 