
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


// recursive Method
// bool searchNode(node* root,int Node){
//     if(root == NULL){
//         return false;
//     }
//     if(root->data ==  Node)
//         return true;

//     if(root->data > Node){
//         return searchNode(root->left,Node);
//     }
//     if(root->data < Node)
//         return searchNode(root->right,Node);
// }


bool searchNode(node* root,int x){
    if(root == NULL)
        return false;
    node* temp = root;

    while(temp != NULL)
    {
        if(x == temp->data)
            return true;
        if(temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

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

int main() {
    node* root = NULL;
    takeInput(root);
    int Node = 9;
    if(searchNode(root,9)) cout << "Yes\n";
    else cout << "Noi\n";
    return 0;
}
 