#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int G[][7],int st,int n){
    static int visited[7]={0};
    int j;
    if(visited[st]==0){
        printf("%d ",st);
        visited[st]=1;
        for(j=1;j<n;j++){
            if(G[st][j]==1 && visited[j]==0){
                DFS(G,j,n);
            }
        }
    }
}

int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    DFS(G,4,7);
    return 0;
}