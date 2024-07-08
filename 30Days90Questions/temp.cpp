/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "bits/stdc++.h"
using namespace std;

class TreeNode {
    public: 

    int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
      }

};

void inorder(TreeNode* root,vector<int> &in){

    if(root == NULL)
        return;

    inorder(root->left,in);

    in.push_back(root->val);

    inorder(root->right,in);
}


void maxSumBST(TreeNode* root) {

    vector<int> inorderVal;
    inorder(root,inorderVal);
    
    vector<int> count;

    int n = inorderVal.size();
    for(int i=1;i<n-1;i++){

        if( (inorderVal[i-1] < inorderVal[i]) && (inorderVal[i] < inorderVal[i+1]) ){
            count.push_back(i);
        }
        else
            count.clear();
    }
    int sum = 0;
    int m = count.size();
    for(int i =0;i<m;i++){
        cout << inorderVal[i] << "  ";
        sum+=inorderVal[i];
    }



    // return sum;
}



int main(){
    TreeNode* root = NULL;
    
    return 0;
}