#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool BFS_helper(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
    queue<int> q;
    q.push(src);
    visited[src]=true;
    unordered_map<int,int> parent;
    parent[src]=src;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=node;
            }
            else if(parent[node]!=i){
                return true;
            }
        }
    }
    return false;
}

bool BFS(int v,int E,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(BFS_helper(i,adj,visited)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int v,E;
    cin>>v>>E;
    vector<vector<int>> edges(E,vector<int>(2));
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    if(BFS(v,E,edges)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}