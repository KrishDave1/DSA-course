#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Problem : Given an array A and an index i return the smallest j such that i < j and A[i]>  2*A[j] + 3 using segment tree using bottom up approach

// Approach : We will build a segment tree where each node will store the smallest index j such that i < j and A[i]>  2*A[j] + 3
// We will start from the leaf nodes and then move upwards to the root node
// For each node we will check if the left child is null or not
// If the left child is null then we will store the index of the right child in the current node

// code:

void build(int *tree,int *a,int index,int s,int e){
    if (s == e){
        tree[index] = s;
        return;
    }
    int mid = (s+e)/2;
    build(tree,a,2*index,s,mid);
    build(tree,a,2*index+1,mid+1,e);
    if (a[tree[2*index]] > a[tree[2*index+1]]){
        tree[index] = tree[2*index+1];
    }
    else{
        tree[index] = tree[2*index];
    }
}

int query(int *tree,int index,int s,int e,int qs,int qe,int *a){
    if (qs > e || qe < s){
        return -1;
    }
    if (s >= qs && e <= qe){
        return tree[index];
    }
    int mid = (s+e)/2;
    int left = query(tree,2*index,s,mid,qs,qe,a);
    int right = query(tree,2*index+1,mid+1,e,qs,qe,a);
    if (left == -1){
        return right;
    }
    if (right == -1){
        return left;
    }
    if (a[left] > a[right]){
        return right;
    }
    return left;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin>>a[i];
    }
    int *tree = new int[4*n+1];
    build(tree,a,1,0,n-1);
    int index;
    cin>>index;
    cout<<query(tree,1,0,n-1,index+1,n-1,a)<<endl;
    return 0;
}


