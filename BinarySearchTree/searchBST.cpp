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

Node* search(Node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }

    // here we know that if it is less than root->data then it will be in left subtree so no need to come to parent that's we do return and not only call the function

    else if(root->data>key){
        return search(root->l,key);
    }
    else
        return search(root->r,key);

    // this function will return the address of the node if it is present otherwise it will return NULL
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
    Node *temp=search(root,key);
    if(temp==NULL){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }
    return 0;
}