// https://acm.cs.nthu.edu.tw/contest/3020/

#include <bits/stdc++.h>
using namespace std;

struct Loli {
    int magic;
    int courage;
};

bool compareByMagicAndCourage(const Loli &a, const Loli &b) {
    if (a.courage == b.courage) return a.magic > b.magic;
    return a.courage > b.courage;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Loli> lolis(N);
    for (int i = 0; i < N; ++i) {
        cin >> lolis[i].magic >> lolis[i].courage;
    }

    // 按勇氣值從大到小排序，如果勇氣值相同則按魔力值從大到小排序
    sort(lolis.begin(), lolis.end(), compareByMagicAndCourage);

    int total_magic = 0, count = 0;

    for (const auto &loli : lolis) {
        if (M <= 0) break;
        if (loli.courage >= M) {
            M -= loli.magic;
            ++count;
        }
    }

    if (M > 0) cout << "-1\n";
    else cout << count << "\n";
}

