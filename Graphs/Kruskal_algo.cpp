#include<bits/stdc++.h>
using namespace std;

void kruskal(vector<pair<int,int>> adj[],int n){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            edges.push_back({it.second,{i,it.first}});
        }
    }
    sort(edges.begin(),edges.end());
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it:edges){
        int u=it.second.first;
        int v=it.second.second;
        int wt=it.first;
        if(parent[u]!=parent[v]){
            cost+=wt;
            mst.push_back({u,v});
            int oldparent=parent[u];
            int newparent=parent[v];
            for(int i=0;i<n;i++){
                if(parent[i]==oldparent){
                    parent[i]=newparent;
                }
            }
        }
    }
    cout<<cost<<endl;
    for(auto it:mst){
        cout<<it.first<<" - "<<it.second<<endl;
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
    kruskal(adj,n);
    return 0;
}