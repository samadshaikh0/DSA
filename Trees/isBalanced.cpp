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
bool isBalanced(node* root){
    
    if(root == NULL)
        return true;
    
    bool left_tree = isBalanced(root->left);
    bool right_tree = isBalanced(root->right);

    bool diff = abs(maxHeight(root->left) - maxHeight(root->right)) <=1;

    if(right_tree && left_tree && diff)
        return true;
    
    return false;
}
//Time complexity-O(N2)

// optimized code
pair<bool,int> isBalancedFast(node* root){

    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left_sub_tree = isBalancedFast(root->left);
    pair<bool,int> right_sub_tree = isBalancedFast(root->right);

    bool left_ans = left_sub_tree.first;
    bool right_ans = right_sub_tree.first;

    bool diff = abs(left_sub_tree.second - right_sub_tree.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left_sub_tree.second,right_sub_tree.second) + 1;

    if(left_ans && right_ans && diff)
        ans.first = true;
    
    else 
        ans.first = false;
    
    return ans;
}


int main(){
    node* root = NULL;
    buildTree(root);
    // 1 3 9 75 -1 -1 -1 10 -1 -1 5 13 -1 -1 19 -1 -1
    cout << "Normal method\n";
    if(isBalanced(root)) cout << "The tree is balanaced\n";
    else cout << "The tree is not balanaced\n";

    cout << "Fast Method\n";
    if(isBalancedFast(root).first) cout << "The tree is balanaced\n";
    else cout << "The tree is not balanaced\n";
    return 0;
}