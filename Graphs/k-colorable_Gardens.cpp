#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> flower;

void bfs(int src){
    queue<int> q;
    sort(adj[src].begin(), adj[src].end());
    for(auto i: adj[src]){
        q.push(i);
    }
    int count = 1;
    while(!q.empty()){
        int j = q.front();
        if (flower[j] == count){
            count++;
        }
        q.pop();
    }
    if (flower[src] == 0){
        flower[src] = count;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    flower = vector<int>(n, 0);
    flower[0] = 1;
    for (int i = 0; i < n; i++){
        bfs(i);
    }
    for (int i = 0; i < n; i++){
        cout << flower[i] << " ";
    }
    cout << endl;
    return 0;
}