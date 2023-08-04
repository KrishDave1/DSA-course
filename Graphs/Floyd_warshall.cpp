#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &graph, int V)
{
    // Initialize the distance matrix with all values set to infinity
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Update the distance matrix based on the given graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // If the source and destination vertices are the same, distance is 0
            if (i == j)
            {
                dist[i][j] = 0;
            }
            // If there is an edge between vertices i and j, update the distance
            else if (graph[i][j] != 0)
            {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Perform the Floyd-Warshall algorithm to find the shortest distances
    // between all pairs of vertices
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If there is a shorter path through vertex k, update the distance
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the resulting shortest distances between all pairs of vertices
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    floyd_warshall(graph, V);
    return 0;
}