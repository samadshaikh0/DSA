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

void diagonalPrintUtil(node* root, int d,map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same 
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical 
    // distance if left child
    diagonalPrintUtil(root->left, 
                      d + 1, diagonalPrint);
 
    // Vertical distance remains 
    // same for right child
    diagonalPrintUtil(root->right, 
                         d, diagonalPrint);
}
 
// Print diagonal traversal 
// of given binary tree
void diagonalPrint(node* root)
{
     
    // create a map of vectors 
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
  



int main(){
    node* root = NULL;
    root = buildTree(root);
    
    diagonalPrint(root);
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    
    return 0;
}