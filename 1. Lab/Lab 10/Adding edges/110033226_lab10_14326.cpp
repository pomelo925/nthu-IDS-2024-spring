//https://acm.cs.nthu.edu.tw/contest/3009/

#include <bits/stdtr1c++.h>
using namespace std;

int num_components = 0; // 初始時，每個節點都是一個獨立的連通分量
int max_size = 1; // 初始時，最大連通分量的大小為1

// find root
int fr(vector<int>& v, int x){
  if(v[x] != x) v[x] = fr(v, v[x]);
  return v[x];
}

// true: connected already
bool unite(vector<int>& v, vector<int>& s, int x, int y){
  int x_root = fr(v,x), y_root = fr(v,y);
  if(x_root == y_root) return true;
	
  if(s[x_root] > s[y_root]) swap(x_root, y_root);
  v[x_root] = y_root;
  s[y_root] += s[x_root];
  num_components--; // 每次合併後，連通分量的數量減少一個
  max_size = max(max_size, s[y_root]); // 更新最大連通分量大小
  return false;
}

int main(){
  int n,m;
  cin >> n >> m;

  num_components=n;
  vector<int> pa(n+1);
  for(int i = 1; i <= n; i++) pa[i] = i;
  vector<int> size(n+1, 1);

  while(m--){
    int v1,v2; cin >> v1 >> v2;
    unite(pa, size, v1, v2);
    cout << num_components << ' ' << max_size << '\n';
  }
}