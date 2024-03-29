#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPartite(int src,vector<vector<int>> &adj,vector<int> &color){
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(color[i]==-1){
                color[i]=1-color[node];
                q.push(i);
            }
            else if(color[i]==color[node]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    
    return 0;
}