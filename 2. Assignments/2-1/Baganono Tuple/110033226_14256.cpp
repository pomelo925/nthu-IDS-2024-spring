//https://acm.cs.nthu.edu.tw/contest/2971/
#include <bits/stdc++.h>
using namespace std;

struct item {
    int value, smaller, bigger;
};

vector<item> v;

void merge_sort(int l, int r) {
    if(l == r) return;

    int m = (l+r)>>1;
    merge_sort(l, m), merge_sort(m+1, r);

    vector<item> tmp;
    int i=l, j=m+1;
    while(i<=m and j<=r) {
        if(v[i].value < v[j].value) {
            v[i].bigger += r-j+1;
            tmp.push_back(v[i]);
            i++;
        }
        else {
            v[j].smaller += i-l;
            tmp.push_back(v[j]);
            j++;
        }
    }

    for(; i<=m; ++i) tmp.push_back(v[i]);
    for(; j<=r; ++j) {
        v[j].smaller += i-l;
        tmp.push_back(v[j]);
    }
    for(int i=l; i<=r; ++i) v[i]=tmp[i-l];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    v.resize(n+5);
    for(int i=1; i<=n; ++i) cin >> v[i].value;
    
    merge_sort(1, n);

    long long ans = 0;
    for(int i=1; i<=n; ++i) ans += 1ll*v[i].bigger*v[i].smaller;
    cout << ans << '\n';
    
    for(auto &n:v) cout << n.value << " ";
}
