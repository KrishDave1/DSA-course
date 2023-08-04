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

void BSTpreorder(int pre[],int n){
    stack<Node *> s;
    Node *root=new Node(pre[0]);
    s.push(root);
    for(int i=1;i<n;i++){
        Node *temp=NULL;
        while(!s.empty() && pre[i]>s.top()->data){
            temp=s.top();
            s.pop();
        }
        if(temp){
            temp->r=new Node(pre[i]);
            s.push(temp->r);
        }
        else{
            s.top()->l=new Node(pre[i]);
            s.push(s.top()->l);
        }
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

void inorder(Node *root){
    
    if (root){
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
    }
}


int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    // Node *root=NULL;
    BSTpreorder(pre,n);
    // inorder(root);
    return 0;
}