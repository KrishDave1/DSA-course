#include<bits/stdc++.h>
using namespace std;

// Shortest Path Length

void shortest_path_length(int src,unordered_map<int,list<int>> &adj,int v){
    unordered_map<int,int> dist;
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
    }
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(dist[i]==INT_MAX){
                dist[i]=dist[node]+1;
                q.push(i);
            }
        }
    }
    for(auto i:dist){
        cout<<"Shortest distance from "<<src<<" to "<<i.first<<" is "<<i.second<<endl;
    }
}

int main(){
    int v,E;
    cin>>v>>E;
    unordered_map<int,list<int>> adj;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    shortest_path_length(src,adj,v);
    return 0;
}