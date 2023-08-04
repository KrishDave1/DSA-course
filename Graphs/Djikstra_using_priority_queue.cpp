#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Djikstra(vector<pair<int,int>> adj[],int V,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        for(auto it:adj[x.second]){
            if(dist[it.first]>dist[x.second]+it.second){
                dist[it.first]=dist[x.second]+it.second;
                pq.push({dist[it.first],it.first});
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