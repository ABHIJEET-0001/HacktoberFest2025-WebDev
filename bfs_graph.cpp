// bfs_graph.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    // n nodes, m edges
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n+1);
    for (int i=0;i<m;i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start; cin >> start;
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[start]=0; q.push(start);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for (int v: g[u]) if (dist[v]==-1) {
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    for (int i=1;i<=n;i++) cout << "Node " << i << " dist=" << dist[i] << "\n";
    return 0;
}
