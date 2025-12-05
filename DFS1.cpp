#include<bits/stdc++.h>
using namespace std;

using ll=long long;

vector<vector<int>>g;
vector<int>visited;

void DFS(int u){
    visited[u]=true;
    cout<<u<<" ";

    for(int v:g[u]){
        if(!visited[v])
            DFS(v);
        }
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,e;
    cout << "Enter number of nodes and edges : "<<flush;
    cin>>n>>e;

    g.resize(n+1);

    visited.assign(n+1,false);

    cout << "Enter each edge : "<<endl;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);

        g[v].push_back(u);
    }

    int start;
    cout << "Enter start node for BFS: "<<flush;
    cin>>start;
    DFS(start);

    return 0;
}
