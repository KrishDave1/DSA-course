#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 10;

int a[n];
int tree[4 * n];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = (tree[2 * node] + tree[2 * node + 1]);

}
//Here the root node is considered at 1 index.
int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l){ // l..r..s...e or s...e..l..r
        return 0;
    }
    if (start >=l && end <= r){
        return tree[node];
    } // l..s..e..r

    //Partial Nodes s..l...e..r or l..s..r..e
    int mid = (start + end) / 2;

    int q1 = query(2 * node, start, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);

    return q1 + q2;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while(1){
        int type;
        cin >> type; 
        if(type == -1){
            break;
        }
        if(type == 1){
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }   
    return 0;
}