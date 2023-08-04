#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *l;
    Node *r;
    Node(int data)
        : data(data), l(NULL), r(NULL)
    {
    }
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->l = insert(root->l, key);
    }
    else if (key > root->data)
    {
        root->r = insert(root->r, key);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        root = insert(root, key);
    }
    inorder(root);
    return 0;
}