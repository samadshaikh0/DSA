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

void buildTreeFromLevelorder(node* &root){
    queue<node* > q;
    cout << "Enter data for root element: " <<endl;

    // creating the root node

    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter data to the left of "<< temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }


        cout << "Enter data to the right of: "<< temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right  = new node(rightData);
            q.push(temp->right);
        }
    }
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




int main(){
    node* root = NULL;
    buildTreeFromLevelorder(root);
    cout << "Printing a tree    "<<endl;
    levelOrderTraversal(root);
    // levelOrderTraversal(root);
    // 1 3 9 75 -1 -1 -1 10 -1 -1 5 13 -1 -1 19 -1 -1
    return 0;
}