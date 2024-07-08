#include <bits/stdc++.h>
#include <vector>

using namespace std;


bool isCBT(node* root, int count, int index){
    if(root == NULL)
        return true;
    
    if(index >= count)
        return false;
    
    else{
        bool left = isCBT(root->left, count, 2*index+1);
        bool right = isCBT(root->right, count, 2*index+2);
        return (left && right);
    }
}

bool isMaxOrder(node* root){
    // case 1:
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    // case 2:
    if(root->right == NULL){
        return root->data > root->left->data; 
    }

    // case 3:
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return left && right && (root->data > root->left->data && root->data > root->right->data);
    }
}

int main() {
    node* root = NULL;
    takeInput(root);

    return 0;
}
