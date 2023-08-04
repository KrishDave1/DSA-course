#include<bits/stdc++.h>
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

// If we want the code in sorted order, we can use set
int main(){
    vector<vector<int>> a = {{0},{2,5},{1,3,4},{2,4},{3,2,5},{1,4}};

    BFS(a, 1, 6);
	// n will be the (number of nodes+1) in the graph
    return 0;
}