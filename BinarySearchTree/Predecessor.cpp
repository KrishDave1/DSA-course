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

Node *findMax(Node *root){
    if(root == NULL){
        return NULL;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

int main(){
    Node* root = newNode(10);
    Node *node = newNode(5);
    root->left = node;
    node = newNode(15);
    root->right = node;
    node = newNode(2);
    root->left->left = node;
    node = newNode(7);
    root->left->right = node;
    node = newNode(12);
    root->right->left = node;
    node = newNode(20);
    root->right->right = node;
    node = newNode(6);
    root->left->right->left = node;
    node = newNode(8);
    root->left->right->right = node;
    node = newNode(11);
    root->right->left->left = node;
    node = newNode(13);
    root->right->left->right = node;
    node = newNode(18);
    root->right->right->left = node;
    node = newNode(22);
    root->right->right->right = node;
    Node *predecessor = findMax(root->left->right->left);
    if(predecessor != NULL){
        cout << predecessor->data << endl;
    }
    else{
        cout << "No predecessor" << endl;
    }
    return 0;
}