#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void BFS(int start){
    queue<int>q;
    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(int v:adj[u]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;
    BFS(start);

    return 0;
}
