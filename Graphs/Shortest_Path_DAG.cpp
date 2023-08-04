#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Topological_Sort_util(int u, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int> &st){
    vis[u] = 1;
    for(auto i: adj[u]){
        if(vis[i.first] == 0){
            Topological_Sort_util(i.first, adj, vis, st);
        }
    }
    st.push(u);
} 

void Shortest_path_DAG(int src,vector<vector<pair<int,int>>> &adj, int v){
    vector<int> vis(v, 0);
    stack<int> st;
    for(int i=0; i<v; i++){
        if(vis[i] == 0){
            Topological_Sort_util(i, adj, vis, st);
        }
    }
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(dist[u] != INT_MAX){
            for(auto i: adj[u]){
                if(dist[i.first] > dist[u] + i.second){
                    dist[i.first] = dist[u] + i.second;
                }
            }
        }
    }
    for(int i=0; i<v; i++){
        cout<<"Node "<<i<<" Distance from source "<<dist[i]<<endl;
    }
}

// In case of finding longest path, we can initialize the dist array with INT_MIN and change the condition in the while loop to dist[u] != INT_MIN and change the condition in the for loop to dist[i.first] < dist[u] + i.second.

int main(){
    int V, E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    int src;
    cin>>src;
    Shortest_path_DAG(src, adj, V);
    return 0;
}