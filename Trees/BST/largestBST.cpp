#include <bits/stdc++.h>
#include <vector>

using namespace std;


class info {
    public:
        int maxi,mini,size;
        bool isBST;

};


info solve(node* root,int &ans){
    if(root == NULL){
        return {INT_MAX,INT_MIN,0,true};
    }

    info left =  solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini) ){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    if(currNode.isBST)
        ans = max(ans, currNode.size);


    return currNode;
}


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







int main() {
    node* root = NULL;
    takeInput(root);
    

    return 0;
}
