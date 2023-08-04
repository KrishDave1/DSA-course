#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void prims(vector<pair<int,int>> adj[],int n){
    vector<int> key(n,INT_MAX);
    vector<int> parent(n,-1);
    vector<bool> mst(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // In priority queue, the first velue is data type of key and second value is data type of value and the third value is comparator.


    // Here this means it is a vector of pair of int,int and the comparator is min heap.
    pq.push({0,0});
    key[0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mst[u]=true;
        for(auto it:adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mst[v]==false && weight<key[v]){
                parent[v]=u;
                key[v]=weight;
                pq.push({key[v],v});
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    prims(adj,n);
    return 0;
}