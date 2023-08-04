#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *l;
    Node *r;
    int h;
    Node(int data)
        : data(data) // if the input is some number then it will be stored in data otherwise it will be stored in l and r
          ,
          l(NULL), r(NULL), h(1)
    {
    }
    // h is the balance factor of each node
} *root = NULL;

int Nodeheight(Node *p) // function to find height of a bst
{
    // int lh, rh;
    // lh = (p && p->l) ? p->l->h : 0; // if p is not null and p's left child is not null, then store p's left child's height in lh, else store 0 in lh
    // rh = (p && p->r) ? p->r->h : 0; // if p is not null and p's right child is not null, then store p's right child's height in rh, else store 0 in rh

    // return lh > rh ? lh + 1 : rh + 1; // return the maximum of lh and rh and add 1 to it
    if (p == NULL)
        return 0;
    return p->h;
}

int BalanceFactor(Node *p)
{
    int lh, rh, h1;

    // /* get heights of left and right subtrees */
    // lh = p && p->l ? p->l->h : 0;
    // rh = p && p->r ? p->r->h : 0;
    h1 = p ? Nodeheight(p) : 0;
    lh = p && p->l ? Nodeheight(p->l) : 0;
    rh = p && p->r ? Nodeheight(p->r) : 0;

    // /* return difference in height */
    // return lh - rh;
    return h1 - lh - rh;
}

Node *LLRotation(Node *p)
{
    Node *pl = p->l;
    Node *plr = pl->r;

    pl->r = p;
    p->l = plr;

    p->h = Nodeheight(p);
    pl->h = Nodeheight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

Node *LRRotation(Node *p)
{
    Node *pl = p->l;
    Node *plr = pl->r;

    pl->r = plr->l;
    p->l = plr->r;

    plr->l = pl;
    plr->r = p;

    pl->h = Nodeheight(pl);
    p->h = Nodeheight(p);
    plr->h = Nodeheight(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

Node *RRRotation(Node *p)
{
    Node *pr = p->r;
    Node *prl = pr->l;
    pr->l = p;
    p->r = prl;
    p->h = Nodeheight(p);
    pr->h = Nodeheight(pr);
    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node *insert(Node *root, int key)
{
    Node *node = new Node(key); // create new node with data as given key.
    if (root == NULL)
    {
        root = node;
        return root;
    }
    if (key < root->data)
    {
        root->l = insert(root->l, key);
    }
    else if (key > root->data)
    {
        root->r = insert(root->r, key);
    }
    root->h = 1 + max(Nodeheight(root->l), Nodeheight(root->r));

    // if (BalanceFactor(root) == 2 && BalanceFactor(root->l) == 1)
    // {
    //     return LLRotation(root);
    // }
    // else if (BalanceFactor(temp)==2 && BalanceFactor(temp->l)==-1){
    //     return LRRotation(root);
    // }
    // else if (BalanceFactor(temp)==-2 && BalanceFactor(temp->r)==-1){
    //     return RRRotation(root);
    // }
    // // else if (BalanceFactor(temp)==-2 && BalanceFactor(temp->r)==1){
    // //     return RLRotation(root);
    // // }
    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->l);
        cout << root->data << " ";
        inorder(root->r);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 2);
    insert(root, 20);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 50);
    preorder(root);
    cout << endl;
    cout << BalanceFactor(root) << " " << BalanceFactor(root->r) << endl;
    // root = RRRotation(root);
    // cout<<BalanceFactor(root)<<endl;
    // preorder(root);
    // cout << endl;
    // // inorder(root);

    return 0;
}