#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// void All_Paths_Util(int u, int d, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, vector<vector<int>> &ans){
//     vis[u] = 1;
//     path.push_back(u);
//     if(u == d){
//         ans.push_back(path);
//     }
//     else{
//         for(auto i: adj[u]){
//             if(vis[i] == 0){
//                 All_Paths_Util(i, d, adj, vis, path, ans);
//             }
//         }
//     }
//     path.pop_back();
//     vis[u] = 0;
// }

// void All_Paths(int s, int d, vector<vector<int>> &adj, int v){
//     vector<int> vis(v, 0);
//     vector<int> path;
//     vector<vector<int>> ans;
//     All_Paths_Util(s, d, adj, vis, path, ans);
//     for(auto i: ans){
//         for(auto j: i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }

void All_Paths_Util(int u, int d, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, vector<vector<int>> &ans) {
    vis[u] = 1;
    path.push_back(u);
    if (u == d) {
        ans.push_back(path);
    } else {
        for (auto i : adj[u]) {
            if (vis[i] == 0) {
                All_Paths_Util(i, d, adj, vis, path, ans);
            }
        }
    }
    vis[u] = 0;
    path.pop_back();
}

void All_Paths(int s, int d, vector<vector<int>> &adj, int v) {
    vector<int> vis(v, 0);
    vector<int> path;
    vector<vector<int>> ans;
    All_Paths_Util(s, d, adj, vis, path, ans);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}


int main(){
    int v, E;
    cin>>v>>E;
    vector<vector<int>> adj(v+1);
    for(int i=1; i<=E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int s, d;
    cin>>s>>d;
    All_Paths(s, d, adj, v);
    return 0;
}