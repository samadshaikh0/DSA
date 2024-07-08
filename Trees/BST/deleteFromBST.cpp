
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


pair<int,int> minMaxValue(node* root){
    if(!root){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> ans;
    node* temp = root;
    while(temp->left != NULL)
        temp = temp->left;
    ans.first = temp->data;

    temp = root;
    
    while(temp->right != NULL)
        temp = temp->right;
    ans.second = temp->data;
    return ans;    
}


node* deleteFromBST(node* &root,int val){
    if(root == NULL){
        return NULL;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 Child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp; 
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp; 
        }

        // 2 children
        if(root->left != NULL && root->right != NULL){
            int maxi = minMaxValue(root).second;
            root->data = maxi;
            root->left = deleteFromBST(root->left,maxi);
            return root;
        }        
    }

    if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    if(root->data < val)
        root->right = deleteFromBST(root->right,val);
        return root;
}


int main() {
    node* root = NULL;
    takeInput(root);
    // 4 2 6 12 53 71 3 23 84 59 19 32
    // cout << minMaxValue(root).second;
    cout << "\nBefore deleting:   ";
    inOrderTraversal(root);
    cout << "\nAfter deleting:    ";
    deleteFromBST(root,59);
    inOrderTraversal(root); 
    return 0;
}
 