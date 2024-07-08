
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


int kthSmallestElementinBST(node* root, int k, int &i) {
    if (root == NULL)
        return -1;

    int left = kthSmallestElementinBST(root->left, k, i);

    if (left != -1)
        return left;

    i++;
    if (i == k)
        return root->data;

    return kthSmallestElementinBST(root->right, k, i);
}



int main() {
    node* root = NULL;
    takeInput(root);
    // 4 2 6 12 53 71 3 23 84 59 19 32
    int i = 0;
    int k = 3;
    inOrderTraversal(root);
    int ans = kthSmallestElementinBST(root,k,i);
    cout << "\nkth smallest element:  "<< ans;

    return 0;
}
 