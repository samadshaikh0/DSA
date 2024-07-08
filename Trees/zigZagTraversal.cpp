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

vector<int> printZigZagPattern(node* root){
    vector<int> result;
    if(root == NULL)
        return result;
    
    queue<node*> q;
    q.push(root);

    // it will indicate the direction.
    bool leftToRight = true;
    while(!q.empty()){
        // to find total number of elements in the current level
        int size = q.size();

        // To store answer of each level
        vector<int> temp(size);
        // processing the level
        for(int i = 0;i<size;i++){
            node* frontNode = q.front();
            q.pop();

            int index = i;
            if(!leftToRight)
                index = size-i-1;
            
            temp[index] = frontNode->data;

            if(frontNode->left) 
                q.push(frontNode->left);
            
            if(frontNode->right)
                q.push(frontNode->right);
        }
        leftToRight = !leftToRight;
        for(auto x:temp){
            result.push_back(x);
        }
    }
    return result;
}


int main(){

    node* root = NULL;
    root = buildTree(root);
    cout << "Level order:   "<<endl;
    levelOrderTraversal(root);

    cout << "ZigZagOrder Traversal: ";
    vector<int> zigzagorder = printZigZagPattern(root);
    for(auto x:zigzagorder) cout << x <<"   ";

    return 0;
}