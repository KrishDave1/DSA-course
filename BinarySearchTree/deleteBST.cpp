#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *l;
    Node *r;
    Node(int data){
        this->data=data;
        l=NULL;
        r=NULL;
    }
};

void insert(Node *&root, int key) {
    Node *node = new Node(key); // Create a new node with the data as given key

    if (root == NULL) { // If the tree is empty, make the new node the root
        root = node;
        return;
    }

    Node *prev = NULL; // Pointer to keep track of the previous node.This will be used when temp becomes NULL so we will insert node to the left or right of prev
    
    Node *temp = root; // Traversal from the root node

    while (temp) { // Traverse the tree to find the appropriate position for insertion

        prev = temp; // Update the previous node to the current node

        if (temp->data > key) { 
            temp = temp->l;
        }
        else if (temp->data < key) { 
            temp = temp->r;
        }
        else
            return;
    }

    // Determine whether to insert the new node as the left or right child of the previous node
    if (prev->data > key) {
        prev->l = node;
    }
    else {
        prev->r = node;
    }
}

void Rinorder(Node *root){
    
    if (root){
    Rinorder(root->l);
    cout<<root->data<<" ";
    Rinorder(root->r);
    }
}

Node* deleteNode(Node* root, int key) {
    if(root==NULL){
        return NULL;
    }
    if(root->data>key){
        root->l=deleteNode(root->l,key);
    }
    else if(root->data<key){
        root->r=deleteNode(root->r,key);
    }
    //Till this point the function is same as search function,now we have to delete the node 
    else{
        if(root->l==NULL){ //If the node has only one child or no child

            Node *temp=root->r; //if root->r is NULL then temp will be NULL otherwise it will take the value of root->r and then we will delete root and return temp
            delete root;
            return temp;

        }
        else if(root->r==NULL){ //same as above
            Node *temp=root->l;
            delete root;
            return temp;
        }
        else{ //If the node has two children
            Node *temp=root->r;
            while(temp->l!=NULL){ //inorder successor(smallest node in the right subtree of root) of the node
                temp=temp->l;
            }
            // Also this can also be done by finding the inorder predecessor(largest node in the left subtree of root) of the node
            root->data=temp->data;
            root->r=deleteNode(root->r,temp->data); // This is done in case the inorder successor has a right child because we know the left is NULL.This process will continue only one time because the inorder successor will not have a left child
        }
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(root,x);
    }
    Rinorder(root);
    cout<<endl;
    int key;
    cin>>key;
    root=deleteNode(root,key);
    Rinorder(root);
    return 0;
}