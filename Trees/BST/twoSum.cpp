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


void inOrderTraversal(node* root,vector<int> &in){
    if(root == NULL){
        return;
    }
    
    inOrderTraversal(root->left,in);
    in.push_back(root->data);
    inOrderTraversal(root->right,in);
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



bool twoSum(node* root,int target){
    if(root == NULL){
        return NULL;
    }

    vector<int> in;
    inOrderTraversal(root,in);

    int i = 0;
    int j = in.size();
    int sum = 0;
    while(i < j){
        sum += in[i] + in[j];
        if(sum == target)
            return true; 
        else if(sum > target)
            j--;
        else 
            i++;
    }
    return false;
}


int main() {
    node* root = NULL;
    takeInput(root);
    if(twoSum(root,1000))
        cout << "\nYes\n";
    else 
        cout << "\nNo\n";

    return 0;
}
