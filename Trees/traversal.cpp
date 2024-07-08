#include "bits/stdc++.h"
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


node* buildTree(node* root){
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
    q.push(NULL); //Level -0 is completed

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



void preOrderTraversal(node* root){
    //N-L-R

    // base condition
    if(root == NULL)
        return ;
    
    
    // 1.N
    cout << root->data <<"  ";
    // 2.L
    preOrderTraversal(root->left);
    // 3.R
    preOrderTraversal(root->right);
}


void postOrderTraversal(node* root){
    //L-R-N

    // base condition
    if(root == NULL)
        return ;
    
    // 1.L
    postOrderTraversal(root->left);
    // 2.R
    postOrderTraversal(root->right);
    // 3.N
    cout << root->data <<"  ";
}

void inOrderTraversal(node* root){
    //L-N-R

    // base condition
    if(root == NULL)
        return ;
    // 1.L
    inOrderTraversal(root->left);
    // 2.N
    cout << root->data <<"  ";
    // 3.R
    inOrderTraversal(root->right);
    
}

int main(){
    node* root = NULL;
    // 1 3 9 75 -1 -1 -1 10 -1 -1 5 13 -1 -1 19 -1 -1

    root = buildTree(root);

    cout << "level Order Traversal :    ";
    levelOrderTraversal(root);
    
    cout << "InOrder Traversal :    ";
    inOrderTraversal(root);
    cout << endl;

    cout << "preOrder Traversal :    ";
    preOrderTraversal(root);
    cout << endl;

    cout << "postOder Traversal :    ";
    postOrderTraversal(root);
    cout << endl;
    
    return 0;
}