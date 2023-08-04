#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS_helper(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,int parent){
    visited[src]=true;
    for(auto i:adj[src]){
        if(!visited[i]){
            if(DFS_helper(i,adj,visited,src)){
                return true;
            }
        }
        else if(i!=parent){
            return true;
        }
    }
    return false;
}

bool DFS(int v,int E,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(DFS_helper(i,adj,visited,-1)){
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
    if(DFS(v,E,edges)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}