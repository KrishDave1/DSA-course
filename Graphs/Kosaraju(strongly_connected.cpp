#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int node,stack<int> &st,vector<bool> &visited){
    visited[node] = true;
    for (auto it:adj[node]){
        if (!visited[it]){
            dfs(adj,it,st,visited);
        }
    }
    st.push(node);
}

void rev_dfs(vector<int> rev_adj[],int node,vector<bool> &visited){
    visited[node] = true;
    cout<<node<<" ";
    for (auto it:rev_adj[node]){
        if (!visited[it]){
            rev_dfs(rev_adj,it,visited);
        }
    }
}

void strongly_connected(vector<int> adj[],vector<int> rev_adj[],int n){
    stack<int> st;
    vector<bool> visited(n,false);
    for (int i = 0;i < n;i++){
        if (!visited[i]){
            dfs(adj,i,st,visited);
        }
    }
    // At this point the stack will contain the nodes in the order of their finishing time
    for (int i = 0;i < n;i++){
        visited[i] = false;
    }
    while (!st.empty()){
        int node = st.top();
        st.pop();
        if (!visited[node]){
            cout<<"SCC: ";
            rev_dfs(rev_adj,node,visited);
            cout<<endl;
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    vector<int> rev_adj[n];
    for (int i = 0;i < m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    strongly_connected(adj,rev_adj,n);
    return 0;
}