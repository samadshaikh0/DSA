#include "bits/stdc++.h"
using namespace std;
// #include "traversal.cpp"

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


node* buildTree(node* &root){
    cout << "Enter Data: " <<endl;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout << "Enter data to insert to the left of  " << data <<"\n";
    root->left = buildTree(root->left);

    cout << "Enter data to insert to the right of  " << data <<"\n";
    root->right = buildTree(root->right);
    return root;
}




 void levelOrderTraversal(node* root){
    queue<node* > q;
    q.push(root);
    q.push(NULL); //Level-0 is completed

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){       //A level is just completed
            cout << "\n";
            if(!q.empty()){
                // q still has children
                q.push(NULL); 
            }
        }

        else{   //Some Value and not a NULL
            cout << temp->data <<" ";

            if(temp->left)
                q.push(temp->left);

                
            if(temp->right)
                q.push(temp->right);
        }
    }

}

int maxHeight(node* root){
    if(root == NULL)
        return 0;
    return max(maxHeight(root->left),maxHeight(root->right))+1;
}


// **********************************************************
pair<bool,int> isSumTree(node* root){
    // base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // base case for leaf nodes
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTree(root->left);
    pair<bool,int> rightAns = isSumTree(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    bool curr = root->data == (leftAns.second + rightAns.second);

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && curr){
        ans.first = true;
        ans.second = 2*root->data;
    }

    else{
        ans.first = false;
    }
    return ans;
}


int main(){

    node* root = NULL;
    root = buildTree(root);
    cout << "\n";
    if(isSumTree(root).first){
        cout << "The tree is sum tree\n";
    }
    else 
        cout << "The tree isn't sum tree\n";


    return 0;
}