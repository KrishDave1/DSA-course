#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &a, int st, int n)
{
    queue<int> q;
    int i = st, j;
    int visited[n] = {0};
    printf("%d ", i);
    visited[i] = 1;
    q.push(i);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (j = 0; j < a[i].size(); j++)
        {
            if (visited[a[i][j]] == 0)
            {
                printf("%d ", a[i][j]);
                visited[a[i][j]] = 1;
                q.push(a[i][j]);
            }
        }
    }
}

void print_Adj(vector<pair<int, vector<int>>> &adj, int V)
{
    for (int i = 1; i <= V; i++)
    {
        cout << i << " Sweet price " << adj[i].first << " Connected to: ";
        for (auto j : adj[i].second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E, s;
    cin >> V >> E >> s;
    vector<pair<int, vector<int>>> adj(V + 1);
    for (int i = 1; i <= V; i++)
    {
        int w;
        cin >> w;
        adj[i].first = w;
    }
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].second.push_back(v);
    }
    print_Adj(adj, V);
    return 0;
}