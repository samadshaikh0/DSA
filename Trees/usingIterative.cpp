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

void inorderIterative(struct node* root)
{
    stack<node*> s;
    node* curr = root;
 
    while (curr != NULL || s.empty() == false) {
         
        // Reach the left most Node of the
        // curr Node
        while (curr != NULL) {
             
            // Place pointer to a tree node on
            // the stack before traversing
            // the node's left subtree
            s.push(curr);
            curr = curr->left;
        }
 
        // Current must be NULL at this point
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr = curr->right;
 
    }
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    // 1 3 9 75 -1 -1 -1 10 -1 -1 5 13 -1 -1 19 -1 -1
    levelOrderTraversal(root);
    cout << endl << "In order Traversal:    ";
    inorderIterative(root);
    return 0;
}