#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Topological_Sort_Util(int u, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
    vis[u] = 1;
    for(auto i: adj[u]){
        if(vis[i] == 0){
            Topological_Sort_Util(i, adj, vis, st);
        }
    }
    st.push(u);
}

void Topological_Sort(vector<vector<int>> &adj, int v){
    vector<int> vis(v, 0);
    stack<int> st;
    for(int i=0; i<v; i++){
        if(vis[i] == 0){
            Topological_Sort_Util(i, adj, vis, st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    int v, E;
    cin>>v>>E;
    vector<vector<int>> adj(v);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    Topological_Sort(adj, v);
    return 0;
}