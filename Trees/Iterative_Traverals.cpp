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
    stack<stu *> s;
    while(p || !s.empty()){
        if(p){
            cout<<(p->data)<<" ";
            s.push(p);
            p = p->l;
        }
        else{
            p = s.top();
            s.pop();
            p = p->r;
        }
    }
}

void Inorder(stu *p){
    stack<stu *> s;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->l;
        }
        else{
            p = s.top();
            s.pop();
            cout<<(p->data)<<" ";
            p = p->r;
        }
    }
}

void Postorder(stu *p){
    stack<long int> s;
    long int temp;
    while(p || !s.empty()){
        if(p){
            s.push((long int)p);
            p = p->l;
        }
        else{
            temp = s.top();
            s.pop();
            if(temp>0){
                s.push(-temp);
                p = ((stu *)temp)->r;
            }
            else{
                cout<<(((stu *)(-1*temp))->data)<<" ";
                p = NULL;
            }
        }
    }
}

void Levelorder(stu *p){
    queue<stu *> q;
    cout<<(p->data)<<" ";
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->l){
            cout<<(p->l->data)<<" ";
            q.push(p->l);
        }
        if(p->r){
            cout<<(p->r->data)<<" ";
            q.push(p->r);
        }
    }
}

int main(){
    cout<<"Creating tree"<<endl;
    CreateTree();
    cout<<"Printing tree"<<endl;
    cout<<"Preorder: ";
    Preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    Inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    Postorder(root);
    cout<<"\nLevelorder: ";
    Levelorder(root);
    cout<<endl;
    return 0;
}