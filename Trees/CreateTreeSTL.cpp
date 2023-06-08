#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node *l;
    struct Node *r;
}stu;

stu *root = new stu;

void CreateTree(){
    stu *p,*t;
    queue<stu *> q;
    cout<<"Enter the root value: ";
    cin>>root->data;
    root->l = root->r = NULL;
    q.push(root);
    while(!q.empty()){
        p = (q.front());
        q.pop();
        cout<<"Enter the left child of "<<p->data<<" : ";
        int x;
        cin>>x;
        if(x!=-1){
            t = new stu;
            t->data = x;
            t->l = t->r = NULL;
            p->l = t;
            q.push(t);
        }
        cout<<"Enter the right child of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            t = new stu;
            t->data = x;
            t->l = t->r = NULL;
            p->r = t;
            q.push(t);
        }
    }
}

void Preorder(stu *p){
    if(p){
        cout<<(p->data)<<" ";
        Preorder(p->l);
        Preorder(p->r);
    }
}


int main(){
    cout<<"Creating tree"<<endl;
    CreateTree();
    cout<<"Printing tree"<<endl;
    Preorder(root);
    return 0;
}