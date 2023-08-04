#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<int> &vis){
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        st.pop();
        if(vis[v] == 0){
            vis[v] = 1;
            cout<<v<<" ";
        }
        for(auto i: adj[v]){
            if(vis[i] == 0){
                st.push(i);
            }
        }
    }
}

int main(){
    int v, E;
    cin>>v>>E;
    vector<vector<int>> adj(v+1);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(v+1, 0);
    for(int i=1; i<=v; i++){
        if(vis[i] == 0){
            DFS(i, adj, vis);
        }
    }

    return 0;
}