#include "bits/stdc++.h"
using namespace std;

class node {
    public :
        int data;
        node*left;
        node*right;

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


node* createMapping(node* root,map<node*,node*> &nodeToParent,int target){
    node* res = NULL;

    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front->data == target)
            res = front;
        
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}


int burnTree(node* root,int target,map<node*,node*> &nodeToParent){
    int time = 0;
    map<node*, bool> visited;
    queue<node* > q;
    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        int size = q.size();
        bool flag = false;

        for(int i = 0;i<size;i++){
        node* front = q.front();
            if(front->left && !visited[front->left]){
                visited[front->left] = true;
                q.push(front->left);
                flag = true;
            }

            if(front->right && !visited[front->right]){
                visited[front->right] = true;
                q.push(front->right);
                falg = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                visited[front] = true;
                q.push(nodeToParent[front]);
                flag = true;
            }
            q.pop();
        }
        if(flag)
            time++;
    }
    return time;
}


int main(){
    node* root = NULL;
    root = buildTree(root);
    

    
}