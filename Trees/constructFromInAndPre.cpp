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

// int findPosition(int in[], int element, int n){
//     for(int i = 0; i<n ;i++){
//         if(in[i] == element)
//             return i;
//     }
//     return -1;
// }


void postorderTraversal(node* &root){
    if(!root)
        return ;
    
    // Left
    postorderTraversal(root->left);

    // right
    postorderTraversal(root->right);

    cout << root->data << " ";
}


void MappingNodeToIndex(int in[], map<int,int> &nodeToIndex,int n){
    for(int i = 0;i<n;i++){
        nodeToIndex[in[i]] = i; 
    }
}

node* solve(int in[],int pre[],int &index,int InsOrderStart,int InsOrderEnd,map<int,int> &nodeToIndex,int n){
    
    //base case
    if(index >= n || InsOrderStart > InsOrderEnd)
        return NULL;

    // create the root node
    int element = pre[index];
    node* root = new node(element);
    index++;

    // find position of element in Inorder array[]

    // int position = findPosition(in,element,n);  
    // TC: Increases due to function call,can be reduced with the help of map
    int position = nodeToIndex[element];

    // recursive call for the left
    root->left = solve(in,pre,index,InsOrderStart,position-1,nodeToIndex,n);

    // recursive call for the right
    root->right = solve(in,pre,index,position+1,InsOrderEnd,nodeToIndex,n);

    return root;



}



int main(){
    node* root = NULL;
    // root = buildTree(root);
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};

    int preOrderindex = 0;
    int InsOrderStart = 0;
    int size = 6;
    int InsOrderEnd = size-1;
    map<int,int> NodeToindex;
    MappingNodeToIndex(in,NodeToindex,size);
    root = solve(in,pre,preOrderindex,InsOrderStart,InsOrderEnd,NodeToindex,size);
    cout << "postorder: ";
    postorderTraversal(root);
    // 1 -1 3 -1 9 -1 7 -1 8 -1 5 -1 -1 
    // 1 2 3 8 9 10 -1 -1 -1 -1 -1 4 -1 -1 -1
}