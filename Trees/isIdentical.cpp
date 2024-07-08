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
bool isIdentical(node* r1,node* r2){
    // base case
    if(r1 == NULL && r2 ==NULL)
        return true;
    
    if( (r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL) )
        return false;
    
    bool left = isIdentical(r1->left,r2->left); 
    bool right = isIdentical(r1->right,r2->right); 

    bool value = r1->data == r2->data;

    if(left && right && value)
        return true;
    else 
        return false;
}


int main(){
    node* root1 = NULL;
    node* root2 = NULL;
    buildTree(root1);
    buildTree(root2);

    // 1 3 9 75 -1 -1 -1 10 -1 -1 5 13 -1 -1 19 -1 -1
    if(isIdentical(root1,root2)) cout << "identical\n";
    else cout << "Not identical\n";


    return 0;
}