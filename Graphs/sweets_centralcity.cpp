#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 14;

int t, n, m, s, d[maxn], a[maxn];
bool inq[maxn];
vector<int> g[maxn];
void solve()
{
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
    {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
    }
    d[s] = a[s];
    queue<int> q({s});
    while (q.size())
    {
        int v = q.front();
        q.pop();
        inq[v] = 0;
        for (auto u : g[v])
            if (d[u] > max(a[u], d[v]))
            {
                d[u] = max(a[u], d[v]);
                if (!inq[u])
                {
                    inq[u] = 1;
                    q.push(u);
                }
            }
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << ' ';
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    memset(d, 63, sizeof d);
    solve();
    fill(inq, inq + n, 0);
    fill(g, g + n, vector<int>());
}