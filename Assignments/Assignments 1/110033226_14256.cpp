//https://acm.cs.nthu.edu.tw/contest/2971/

#include <bits/stdc++.h>

struct Node {
    int l, r, min;
};

Node tree[4 * 100000];

void build(int a[], int n) {
    for (int i = 0; i < 4 * n; i++) {
        tree[i].l = tree[i].r = tree[i].min = 0;
    }
    def build_helper(int l, int r, int i) {
        if (l == r) {
            tree[i].min = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build_helper(l, mid, i * 2);
        build_helper(mid + 1, r, i * 2 + 1);
        tree[i].min = min(tree[i * 2].min, tree[i * 2 + 1].min);
    }
    build_helper(0, n - 1, 1);
}

int query(int i, int j) {
    def query_helper(int l, int r, int i, int j, int k) {
        if (l > j || r < i) {
            return 0;
        }
        if (l >= i && r <= j) {
            return tree[k].min;
        }
        int mid = (l + r) / 2;
        return min(query_helper(l, mid, i, j, k * 2), query_helper(mid + 1, r, i, j, k * 2 + 1));
    }
    return query_helper(0, n - 1, i, j, 1);
}

int solve(int a[], int n) {
    build(a, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += query(i, j);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = solve(a, n);
    cout << ans << endl;
    return 0;
}
