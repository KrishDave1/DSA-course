#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Djikstra using set

void Djikstra(vector<pair<int,int>> adj[],int V,int src){
    set<pair<int,int>> s;
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    s.insert({0,src});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:adj[x.second]){
            if(dist[it.first]>dist[x.second]+it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<"Distance from source to "<<i<<" is "<<dist[i]<<endl;
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // for undirected graph
    }
    Djikstra(adj,V,0);
    return 0;
}