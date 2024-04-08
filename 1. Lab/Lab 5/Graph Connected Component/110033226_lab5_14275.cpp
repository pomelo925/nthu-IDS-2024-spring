#include <iostream>
#include <vector>
using namespace std;
using LL = long long int;

void dfs(int u, vector< vector<int> > &adj, vector<bool> &vis){
    vis[u] = true;
    for (auto v : adj[u]) if (!vis[v]) dfs(v, adj, vis);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > adjacency_list(n);
        vector<bool> visited(n, false);
        
        while (m--) {
            int u, v; cin >> u >> v;
            u--; v--;
            adjacency_list[u].emplace_back(v);
            adjacency_list[v].emplace_back(u);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adjacency_list, visited);
                count++;
            }
        }

        cout << count;
		if(t > 0) cout<<'\n';
    }

}