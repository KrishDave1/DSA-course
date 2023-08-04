#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS_helper(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &temp){
    visited[src]=true;
    temp.push_back(src);
    for(auto i:adj[src]){
        if(!visited[i]){
            DFS_helper(i,adj,visited,temp);
        }
    }
}

vector<vector<int>> DFS(int v,int E,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> temp;
            DFS_helper(i,adj,visited,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main(){
    int v,E;
    cin>>v>>E;
    vector<vector<int>> edges(E,vector<int>(2));
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>> ans=DFS(v,E,edges);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
}