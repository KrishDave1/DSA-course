#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> G[],int st,int n){
    static int visited[7]={0};
    int j;
    if(visited[st]==0){
        printf("%d ",st);
        visited[st]=1;
        for(j=0;j<G[st].size();j++){
            if(visited[G[st][j]]==0){
                DFS(G,G[st][j],n);
            }
        }
    }
}

int main(){
    int i;
    vector<int> G[7];
    G[1].push_back(2);
    G[1].push_back(3);
    G[2].push_back(1);
    G[2].push_back(4);
    G[3].push_back(1);
    G[3].push_back(4);
    G[4].push_back(5);
    G[4].push_back(2);
    G[4].push_back(3);
    G[4].push_back(6);
    G[5].push_back(4);
    G[6].push_back(4);
    DFS(G,1,7);
    return 0;
}