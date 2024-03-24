//https://acm.cs.nthu.edu.tw/contest/2971/

#include <bits/stdc++.h>
using namespace std;

void kill(vector<int>& alive, int a, int b, bool backward) {
    if(backward) {
        for(int i=0; i<b && (a-i)>0; ++i) {
            if(alive[a-i]) {
                cout << (a-i) << " ";
                alive[a-i] = 0; // 標記為已殺
            }
        }
    } else {
        for(int i=1; i<=b && (a+i)<alive.size(); ++i) {
            if(alive[a+i]) {
                cout << (a+i) << (i<b ? " " : "");
                alive[a+i] = 0; // 標記為已殺
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> alive(n+2, 1); // 擴展一點範圍以簡化邊界檢查

    while(k--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) kill(alive, a, b, false); // 向後殺
        else kill(alive, a, b, true); // 向前殺
        cout << "\n";
    }

    return 0;
}


