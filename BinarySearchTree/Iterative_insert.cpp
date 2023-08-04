#include <bits/stdc++.h>
using namespace std;

// BST Node
class Node {
public:
	int data;
	Node* l;
	Node* r;
	Node(int data)
		: data(data) //if the input is some number then it will be stored in data otherwise it will be stored in l and r
		, l(NULL)
		, r(NULL)
	{
	}
};

void insert(Node*& root, int key)
{
	Node* node = new Node(key); // create new node with data as given key
	if (root==NULL) {
		root = node;
		return;
	}
	Node* prev = NULL;// Pointer to keep track of the previous node.This will be used when temp becomes NULL so we will insert node to the left or right of prev

	Node* temp = root;// Traversal from the root node

	while (temp) {// Traverse the tree to find the appropriate position for insertion

        prev = temp;// Update the previous node to the current node

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

	if (prev->data > key)
		prev->l = node;
	else
		prev->r = node;
	
	return;
}

void inorder(Node* root)
{
    if (root) {
        inorder(root->l);
        cout << root->data << " ";
        inorder(root->r);
    }
}

int main()
{
    Node* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(root,x);
    }
    inorder(root);
    return 0;
}
