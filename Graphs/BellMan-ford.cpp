#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Bellman ford algorithm is used to find the shortest path from a source vertex to all other vertices in a weighted directed graph.
void bellman_ford(vector<vector<int>> &edges,int V,int E,int src){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V-1;i++){
        // Here the outer loop will give the shortest path from source to all vertices
        for (int j = 0; j < E;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    // This loop iterates one more time to check if there is a negative cycle in the graph.
    for (int i = 0; i < E;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "Negative cycle found" << endl;
            return;
        }
    }
    for (int i = 0; i < V;i++){
        cout<<"Vertex "<<i<<" Distance from source "<<dist[i]<<endl;
    }
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;
    for (int i = 0; i < E;i++){
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp = {u, v, w};
        edges.push_back(temp);
    }
    bellman_ford(edges, V, E, 0);
    return 0;
}