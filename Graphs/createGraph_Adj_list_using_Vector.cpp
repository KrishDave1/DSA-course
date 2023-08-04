#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int n)
{
	for (int v = 1; v <= n; ++v) {
		cout<<v<<"->";
		for (auto x : adj[v])
			cout << x << " ";
		cout << endl;
	}
}

int main()
{
	int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> adj[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
	printGraph(adj, n);
	return 0;
}
