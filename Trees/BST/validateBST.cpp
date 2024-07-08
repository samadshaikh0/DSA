
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


bool validate(node* root, int min, int max){

    // base case
    if(root == NULL)
        return true;
    
    if( root->data >= min && root->data <= max ) {
        bool left = validate(root->left, min, root->data);
        bool right = validate(root->right, root->data, max);
        return left && right;
    }
    else 
        return false;
}


int main() {
    node* root = NULL;
    takeInput(root);
    // 4 2 6 12 53 71 3 23 84 59 19 32
    inOrderTraversal(root);
    if( validate(root, INT_MIN, INT_MAX) )
        cout << "\nYES\n";
    else 
        cout << "\nNO\n";

    return 0;
}
 