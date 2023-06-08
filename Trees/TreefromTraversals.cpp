#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *l;
        Node *r;
        Node(int data){
            this->data = data;
            l = r = NULL;
        }
};

int search(int in[],int s,int e,int curr){
    for(int i=s;i<=e;i++){
        if (in[i]==curr){
            return i;
        }
    }
    return -1;
}

Node *buildTree(int pre[],int in[],int s,int e){
    static int id=0;
    if (s>e){
        return NULL;
    }
    int curr=pre[id];
    id++;
    //inorder will change in each call while the preorder will remain same 
    
    Node *t = new Node(curr);
    if (s==e){
        return t;
    }
    int pos = search(in,s,e,curr);// Bcoz s and e will change in each call 
    t -> l= buildTree(pre,in,s,pos-1);
    t -> r= buildTree(pre,in,pos+1,e);

    return t;
}

void inorder(Node *root){
    if(root){
        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
    }
}

int main(){
    int pre[] = {1,2,4,3,5};
    int in[] = {4,2,1,5,3};
    Node *root = new Node(0);
    root = buildTree(pre,in,0,4);
    inorder(root);

    return 0;
}