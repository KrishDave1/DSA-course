#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> visited;

bool isSafe(int i,int j,int R,int C){
    if (i >= 0 && j >= 0 && i < R && j < C && adj[i][j] && !visited[i][j]) {
        return true;
    }
    return false;
}

void floodfill(int src_i,int src_j,int R,int C,int color){
    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, 1, -1};
    queue<pair<int,int>> q;
    pair<int, int> p = make_pair(src_i, src_j);
    q.push(p);
    visited[src_i][src_j] = 1;
    adj[src_i][src_j] = color;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4;k++){
            if (isSafe(i + row[k], j + col[k], R, C)){
                visited[i + row[k]][j + col[k]] = 1;
                adj[i + row[k]][j + col[k]] = color;
                pair<int, int> p = make_pair(i + row[k], j + col[k]);
                q.push(p);
            }
        }
    }
}

int main(){
    int R, C;
    cin >> R >> C;
    adj.resize(R, vector<int>(C));
    visited.resize(R, vector<int>(C));
    for (int i = 0; i < R;i++){
        for (int j = 0; j < C;j++){
            cin >> adj[i][j];
            visited[i][j] = 0;
        }
    }
    int src_i, src_j;
    cin >> src_i >> src_j;
    int color;
    cin >> color;
    floodfill(src_i, src_j, R, C, color);
    for (int i = 0; i < R;i++){
        for (int j = 0; j < C;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}