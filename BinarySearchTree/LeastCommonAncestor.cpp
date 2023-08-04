#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *insertNode(Node *root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* LCA(Node* root, int l, int r){
    if(root == NULL || l>r){
        return NULL;
    }
    if(root->data > l && root->data > r){
        return LCA(root->left, l, r);
    }
    if(root->data < l && root->data < r){
        return LCA(root->right, l, r);
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insertNode(root, 20);
    insertNode(root, 8);
    insertNode(root, 22);
    insertNode(root, 4);
    insertNode(root, 12);
    insertNode(root, 10);
    insertNode(root, 14);
    Node* lca = LCA(root, 11, 14);
    cout<<lca->data;
    return 0;
}