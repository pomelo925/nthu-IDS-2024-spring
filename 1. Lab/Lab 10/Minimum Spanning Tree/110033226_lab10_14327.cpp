//https://acm.cs.nthu.edu.tw/contest/3009/

#include <bits/stdc++.h>
using namespace std;
 
vector<int> fa, sz;
 
int find(int u) {
	return (u == fa[u] ? u : fa[u] = find(fa[u]));
}
 
bool unite(int u, int v) {
	int ru = find(u), rv = find(v);
	if(ru == rv) return false;
	if(sz[ru] < sz[rv]) swap(ru, rv);
	fa[rv] = ru;
	sz[ru] += sz[rv];
	return true;
}
 
int main() {
	int n, m; cin >> n >> m;

	fa.assign(n + 1, 0), sz.resize(n + 1, 1);
	for(int i = 1; i <= n;i++) fa[i] = i;

	vector<tuple<int, int,int>> Edges(m);
	for(auto &[w, u, v] : Edges) cin >> u >> v >> w;

	sort(Edges.begin(), Edges.end());

	long long ans = 0;
	for(auto [w, u, v] : Edges) {
		if(unite(u, v)) ans += w; 
	}
	cout << ans << '\n';
}