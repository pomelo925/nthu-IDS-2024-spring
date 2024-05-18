//https://acm.cs.nthu.edu.tw/contest/3009/

#include<bits/stdc++.h>
using namespace std;

vector<int> fa,sz;
int cnt, max_sz;
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
	int root_x = find(x), root_y = find(y);
	if(root_x == root_y) return;
	if(sz[root_x] < sz[root_y]) swap(x,y);
	cnt--;
	sz[root_x] += sz[root_y];
	fa[root_y] = root_x;
	if(max_sz < sz[root_x]) max_sz = sz[root_x];
}

signed main() {
	int n,m;cin>>n>>m;
	for(int i=0;i<=n;i++) {
		fa.emplace_back(i);
		sz.emplace_back(1);
	}

	cnt = n, max_sz = 1;
    
	while(m--) {
		int u,v;cin>>u>>v;
		unite(u,v);
		cout<<cnt<<' '<<max_sz<<'\n';
	}
}