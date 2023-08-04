#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void BFS(int G[][7], int st, int n)
{
    queue<int> q;
    int i = st, j;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    q.push(i);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int main()
{
	int G[7][7] = { {0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 1, 1, 0, 0, 0},
	                {0, 1, 0, 0, 1, 0, 0}, 
	                {0, 1, 0, 0, 0, 1, 0},
	                {0, 0, 1, 1, 0, 1, 1},
	                {0, 0, 0, 0, 1, 0, 0},
	                {0, 0, 0, 0, 1, 0, 0}
	                };

	BFS(G, 1, 7);

	return 0;
}