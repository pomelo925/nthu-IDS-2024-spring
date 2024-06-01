#include <bits/stdc++.h>
using namespace std;

// 并查集数据结构
struct DisjointSet {
  vector<int> parent, rank;
  DisjointSet(int n) : parent(n), rank(n, 0) {
    for (int i=0; i<n; ++i) parent[i] = i;
  }

  int find(int u) {
    if(u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
  }

  bool unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return false;

    if(rank[pu] < rank[pv]) parent[pu] = pv;
    else if(rank[pu] > rank[pv]) parent[pv] = pu;
    else{
      parent[pv] = pu;
      rank[pu]++;
    }
    return true;
  }
};

int main() {
  int N;
  cin >> N;
  
  vector<pair<int, int>> coordinates(N);
  for (int i=0; i<N; ++i) {
    cin >> coordinates[i].first >> coordinates[i].second;
  }
  
  vector<tuple<int, int, int>> edges;
  for (int i=0; i<N; ++i) {
    for (int j=i+1; j<N; ++j) {
      int weight = pow(coordinates[i].first - coordinates[j].first, 2) +
                  pow(coordinates[i].second - coordinates[j].second, 2);
      edges.emplace_back(weight, i, j);
    }
  }
    
  // 按权重排序边
  sort(edges.begin(), edges.end());
  
  DisjointSet ds(N);
  int totalCost=0, edgesUsed=0;
  
  // 遍历边并选择最小生成树的边
  for (const auto& [weight, u, v] : edges) {
    if(ds.unite(u, v)) {
      totalCost += weight;
      edgesUsed++;
      if(edgesUsed == N-1) break; // 最小生成树有 N-1 条边
    }
  }

  cout << totalCost << endl;
  return 0;
}
