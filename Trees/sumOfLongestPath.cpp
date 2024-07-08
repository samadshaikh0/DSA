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


void sumOfLongRootToLeafPath(node *root,int sum,int &maxSum,int len,int &maxLen){
    // base case
    if(root == NULL){
        // if current length of the path is greater than the maximum length
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }

        else if(len == maxLen){
            maxSum = max(sum,maxSum);
        }
        return ;
    }

    sum = sum + root->data;

    // traversing left sub tree
    sumOfLongRootToLeafPath(root->left,sum,maxSum,len+1,maxLen);


    // traversing right sub tree
    sumOfLongRootToLeafPath(root->right,sum,maxSum,len+1,maxLen);
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    int maxSum = 0;
    int maxLen = 0;
    sumOfLongRootToLeafPath(root,0,maxSum,0, maxLen);
    cout << "Ths sum is:    ";
    cout << maxSum << endl;

    cout << "The length is: ";
    cout << maxLen <<endl;


}