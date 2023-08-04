#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define bit(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1 << (i))
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
const int maxn = 1e6 + 5;
const ll oo = 2e18 + 5;
const int MOD = 1e9 + 7;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
struct node
{
    int u, v, w, id;
    node(int _u = 0, int _v = 0, int _w = 0, int _id = 0)
    {
        u = _u, v = _v, w = _w, id = _id;
    }
    bool operator<(const node &other) const
    {
        return w < other.w;
    }
};
struct DSU
{
    int n;
    vector<int> sz, pa;
    DSU(int _n = 0)
    {
        n = _n;
        sz.resize(n + 5, 1);
        for (int i = 0; i <= n; i++)
            pa.push_back(i);
    }
    int Find(int u)
    {
        return u == pa[u] ? u : pa[u] = Find(pa[u]);
    }
    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        sz[a] += sz[b];
        pa[b] = a;
        return true;
    }
};
int n, m, depth[maxn], child[maxn], par[maxn][20], cost[maxn][20];
vector<pair<int, int>> adj[maxn];
node edge[maxn];
ll ans[maxn];
void dfs(int u, int pre)
{
    for (int it = 0; it < (int)adj[u].size(); it++)
    {
        int v = adj[u][it].ff, w = adj[u][it].ss;
        if (v == pre)
            continue;
        depth[v] = depth[u] + 1;
        cost[v][0] = w;
        par[v][0] = u;
        for (int j = 1; MASK(j) <= n; j++)
        {
            par[v][j] = par[par[v][j - 1]][j - 1];
            cost[v][j] = max(cost[v][j - 1], cost[par[v][j - 1]][j - 1]);
        }
        dfs(v, u);
    }
}
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int ans = 0;
    for (int j = 19; j >= 0; j--)
        if (depth[u] - MASK(j) >= depth[v])
            ans = max(ans, cost[u][j]), u = par[u][j];
    if (u == v)
        return ans;
    for (int j = 19; j >= 0; j--)
        if (par[u][j] != par[v][j])
        {
            ans = max({ans, cost[u][j], cost[v][j]});
            u = par[u][j];
            v = par[v][j];
        }
    return max({ans, cost[u][0], cost[v][0]});
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = node(u, v, w, i);
    }
    sort(edge + 1, edge + m + 1);
    DSU dsu(n);
    ll summst = 0;
    vector<int> tmp;
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w, id = edge[i].id;
        if (dsu.Union(u, v))
        {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
            summst += w;
            tmp.push_back(id);
        }
    }
    for (int it = 0; it < (int)tmp.size(); it++)
        ans[tmp[it]] = summst;
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        if (!ans[edge[i].id])
        {
            int u = edge[i].u, v = edge[i].v, w = edge[i].w, id = edge[i].id;
            ;
            ans[edge[i].id] = summst - lca(u, v) + w;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}
int main()
{
    init();
    solve();
    return 0;
}