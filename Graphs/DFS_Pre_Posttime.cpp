#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Time = 1;

void dfs(int u, vector<vector<int>> &adj, vector<int> &pre, vector<int> &post, vector<int> &vis)
{
    vis[u] = 1;
    pre[u] = Time++;
    for (auto i : adj[u])
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, pre, post, vis);
        }
    }
    post[u] = Time++;
}

int main()
{
    int v, E;
    cin >> v >> E;
    vector<vector<int>> adj(v);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> pre(v + 1);
    vector<int> post(v + 1);
    vector<int> vis(v + 1, 0);

    dfs(0, adj, pre, post, vis);

    for (int i = 0; i < v; i++)
        cout << "Node " << i << " Pre number "
             << pre[i] << " Post number "
             << post[i] << endl;

    return 0;
}