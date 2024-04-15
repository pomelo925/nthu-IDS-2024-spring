#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    list<int> seq;
    unordered_map<int, list<int>::iterator> pos;

    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        seq.push_back(x);
        pos[x] = prev(seq.end());
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x, y; cin >> x >> y;
            auto it = pos[x];
            seq.insert(next(it), y);
            pos[y] = next(it);
        } else {
            int x;
            cin >> x;
            seq.erase(pos[x]);
            pos.erase(x);
        }
    }

    for (auto it = seq.begin(); it != seq.end(); ++it) {
        cout << *it;
        if (next(it) != seq.end()) cout << ' ';
    }
    return 0;
}