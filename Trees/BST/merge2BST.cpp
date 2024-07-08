#include <bits/stdc++.h>
#include <vector>

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

node* insertIntoBST(node* &root,int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data)
        root->right = insertIntoBST(root->right,data);


    else if(data < root->data)
        root->left = insertIntoBST(root->left,data);

    return root;
}


void takeInput(node* &root){
    int data;
    cout << "Enter data: ";
    cin >> data;

    while(data != -1){
        insertIntoBST(root,data);
        cout << "Enter data: ";
        cin >> data;
    }
}


void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    // in.push_back(root->data);
    inOrderTraversal(root->right);
}

// Step 1:
void BSTtoSortedDLL(node* root,node* &head){
    // base case
    if(root == NULL)    
        return;
    
    // conversion of right sub tree into linkedlist
    BSTtoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL)
        head->left = root;
    
    head = root;

    BSTtoSortedDLL(root->left, head);
}


// step 2:
node* mergeTwoDLL(node* head1, node* head2){
    node* head = NULL;
    node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){ 
                head = head1;
                tail = head1;
                head1 = head1->right;
            }

            else {  //insert At end
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }


        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{  //insert at end
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}



// step 3: Convert a sorted DLL into a BST

// too find total number of nodes in BST
int countNodes(node* head){
    node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}


node* sortedDLLtoBST(node* &head, int n){
    if( n<=0 || head == NULL)
        return NULL;

    // Coverting left part of DLL into BST

    node* leftSubTree = sortedDLLtoBST(head,n/2);

    node* root = head;
    root->left = leftSubTree;

    head = head->right;
    // call for right part
    sortedDLLtoBST(head,(n-n/2-1));

    return root;
}



int main() {
    node* root1 = NULL;
    node* root2 = NULL;
    
    
    return 0;
}
