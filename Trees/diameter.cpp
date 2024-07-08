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
int diameter(node* root){
    // base case
    if(root == NULL)
        return 0;
    
    int left = diameter(root->left);
    int right = diameter(root->right);

    int op3 = maxHeight(root->left)+maxHeight(root->right)+1;
    return max(max(left,right), op3);
}
//Time complexity-O(N2)

// optimized code
pair<int,int> fastDiameter(node* root){

    // base case
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p; 
    }

    pair<int,int> left = fastDiameter(root->left);
    pair<int,int> right = fastDiameter(root->right);

    int left_sub_tree = left.first; 
    int right_sub_tree = right.first; 

    int comb = left.second + right.second + 1;
    pair<int,int> ans;
    ans.first = max(max(left_sub_tree,right_sub_tree),comb);
    ans.second = max(left.second,right.second)+1;

    return ans;
    
}


int main(){
    node* root = NULL;
    buildTree(root);
    // 1 3 9 75 -1 -1 -1 10 -1 -1 5 13 -1 -1 19 -1 -1

    cout << "Diameter of the tree is:   "<< diameter(root) <<endl;
    cout << "Diameter of the tree using fast method is:   "<< fastDiameter(root).first <<endl;

    return 0;
}