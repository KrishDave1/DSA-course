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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);

}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for(int i = 0; i < 10; i++)
        cout << tree[i] << " ";
       
    return 0;
}