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


void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    // in.push_back(root->data);
    inOrderTraversal(root->right);
}







node* preorderToBST(vector<int> &pre, int &i, int maxi, int mini) {
    if (i >= pre.size())
        return NULL;

    if ( pre[i] < mini || pre[i] > maxi )
        return NULL;

    node* root = new node(pre[i]);
    i++;

    root->left = preorderToBST(pre, i, root->data, mini);
    root->right = preorderToBST(pre, i, maxi, root->data);

    return root;
}




int main() {
    node* root = NULL;
    vector<int> pre = {8,3,1,10,6,4,7,14,13};
    int index = 0;
    node* newRoot = preorderToBST(pre,index,INT_MAX,INT_MIN);
    inOrderTraversal(newRoot);
    return 0;
}
