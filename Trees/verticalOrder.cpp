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


vector<int> verticalLevelOrder(node* &root){
    vector<int> ans;
    if(!root) return ans;

    map<int,map<int,vector<int> > > Nodes;
    queue<pair<node *,pair<int,int> > > q;
    
    // pushing the root node with lvl = 0,hd = 1
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        // creating an instant of a queue
        pair<node *,pair<int,int> > temp;
        temp = q.front();
        node* firstNode = temp.first;

        int hd = temp.second.first;
        int lvl = temp.second.second;

        Nodes[hd][lvl].push_back(firstNode->data);

        // Moving into left
        if(firstNode->left)
            q.push(make_pair(firstNode->left,make_pair(hd-1,lvl+1)));

        // Moving into right sub-tree
        if(firstNode->right)
            q.push(make_pair(firstNode->right,make_pair(hd+1,lvl+1)));
            q.pop();
    }
    for(auto x:Nodes){          //x->{int,map}
        for(auto y:x.second){       //y->map = {int,vector<int>}
            for(auto z:y.second){       //z->vector<int>
                ans.push_back(z); 
            }

        }
    }
    return ans;
}



int main(){
    
    node* root = NULL;
    root = buildTree(root);
    vector<int> results = verticalLevelOrder(root);

    for(auto y:results) cout << y <<"   ";
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1 

    return 0;
}