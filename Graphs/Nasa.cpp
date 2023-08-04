#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector <vector <long long int>> adj;
unordered_map <long long int,long long int> mp;
vector <long long int> vis;
long long int No_of_comp(long long int N){
    long long int count = 1;
    for (long long int i = 0; i < N;i++){
        if (!vis[i]){
            queue <long long int> q;
            q.push(i);
            vis[i] = 1;
            long long int n = 0;
            while (!q.empty()){
                n++;
                long long int u = q.front();
                q.pop();
                vis[u] = 1;
                for (auto j : adj[u]){
                    if (!vis[j]){
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
            mp[count] = n;
            count++;
        }
    }
    return count;
}
long long int No_of_pairs(long long int n){
    long long int count = 0;
    for (auto i : mp){
        count += i.second;
    }
    long long int no_pairs = 0;
    for (auto i : mp){
        no_pairs += ((i.second*(count-i.second)));
    }
    return no_pairs/2;
}
int main(){
    long long int n, m;
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n, 0);
    mp.clear();
    for (long long int i = 0; i < m;i++){
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    long long int count = No_of_comp(n);
    cout << No_of_pairs(count) << endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<endl;
    }
    for (auto i:mp){
        cout << i.first << " " << i.second << endl;
    }
}