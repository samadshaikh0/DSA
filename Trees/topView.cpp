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

vector<int> topview(node* root){
    vector<int> ans;
    if(!root)
        return ans;
    
    map<int,int> Nodes;
    queue<pair<node* ,int> > q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        node* frontNode = temp.first;

        int hd = temp.second;
        if(!Nodes[hd])
            Nodes[hd] = frontNode->data;
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));
        
        if(frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));
        q.pop();
    }
    
    for(auto x:Nodes){
        ans.push_back(x.second);
    }
    return ans;

}

 



int main(){
    node* root = NULL;
    root = buildTree(root);
    vector<int> result = topview(root);
    // 1 2 3  -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    for(auto x:result) cout << x << "   ";
    return 0;
}