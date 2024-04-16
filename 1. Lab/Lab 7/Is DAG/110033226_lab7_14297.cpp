#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> deg(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		deg[v]++;
	}
	queue<int> que;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) {
			que.push(i);
		}
	}
	vector<int> ans;
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		ans.push_back(u);
		for(auto v : g[u]) {
			deg[v]--;
			if(deg[v] == 0) {
				que.push(v);
			}
		}
	}
	cout << ((int) ans.size() == n ? "YES" : "NO") << "\n";
	return 0;
}
