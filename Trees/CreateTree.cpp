#include<iostream>
#include<bits/stdc++.h>
using namespace std;


typedef struct Node{
    int data;
    struct Node *l;
    struct Node *r;
}stu;

stu *root = new stu;

//Create a Queue data structure without stl
struct Queue{
    int size;
    int front;
    int rear;
    stu **Q;
};

void create(struct Queue *q,int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (stu **)malloc(q->size*sizeof(stu *));
}

void enqueue(struct Queue *q,stu *x){
    if(q->rear == q->size-1){
        cout<<"Queue is full"<<endl;
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

stu * dequeue(struct Queue *q){
    stu *x = NULL;
    if(q->front == q->rear){
        cout<<"Queue is empty"<<endl;
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}

void CreateTree(){
    stu *p,*t;
    struct Queue q;
    create(&q,100);
    cout<<"Enter the root value: ";
    cin>>root->data;
    root->l = root->r = NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout<<"Enter the left child of "<<p->data<<" : ";
        int x;
        cin>>x;
        if(x!=-1){
            t = new stu;
            t->data = x;
            t->l = t->r = NULL;
            p->l = t;
            enqueue(&q,t);
        }
        cout<<"Enter the right child of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            t = new stu;
            t->data = x;
            t->l = t->r = NULL;
            p->r = t;
            enqueue(&q,t);
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

void Inorder(stu *p){
    if (p){
        Inorder(p->l);
        cout<<(p->data)<<" ";
        Inorder(p->r);
    }
}

void Postorder(stu *p){
    if (p){
        Postorder(p->l);
        Postorder(p->r);
        cout<<(p->data)<<" ";
    }
}

int main(){
    cout<<"Creating tree"<<endl;
    CreateTree();
    cout<<"Printing tree"<<endl;
    Preorder(root);
    return 0;
}