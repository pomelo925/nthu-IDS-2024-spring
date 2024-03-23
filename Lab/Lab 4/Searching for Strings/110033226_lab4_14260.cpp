#include <bits/stdc++.h>
using namespace std;

// 定義常數
constexpr int MOD = 1E9 + 9; // 計算哈希時的模數
constexpr int A = 998244353; // 基數
constexpr int N = 2E5 + 5;   // 最大長度限制

int power[N]; // 用於存儲 A 的幂次

int main() {
    // 初始化 A 的幂次，用於後續的哈希計算
    power[0] = 1;
    for(int i=1; i<N; i++) power[i] = 1LL * power[i - 1] * A % MOD;

    // 讀入字符串 s 和 t
    string s, t;
    cin >> s >> t;
    int n=(int)s.size(), m=(int) t.size();

    // 計算字符串 s 中每個字符的出現次數
    array<int, 26> cnt = {};
    for(char c:s) cnt[c-'a']++;

    // 預處理字符串 t 的哈希值
    vector<int> hsh(m);
    hsh[0] = t[0];
    for(int i=1; i<m; i++) hsh[i] = (1LL * hsh[i - 1] * A + t[i]) % MOD;

    // 定義一個 lambda 函數，用於計算子字符串的哈希值
    auto get = [&](int i, int j) -> int {
        if(i == 0) return hsh[j];
        return ((hsh[j] - 1LL * hsh[i - 1] * power[j - i + 1]) % MOD + MOD) % MOD;
    };  

    // 用於儲存匹配成功的子字符串的哈希值
    vector<int> matched;
    vector<array<int, 26>> pref(m + 1);
    for(int i = 0; i < m; i++) {
        pref[i + 1] = pref[i];
        pref[i + 1][t[i] - 'a']++;
        // 當達到 s 的長度時，開始檢查是否匹配
        if(i >= n - 1) {
            array<int, 26> diff = {};
            for(int j = 0; j < 26; j++) diff[j] = pref[i + 1][j] - pref[i + 1 - n][j];
            if(cnt == diff) matched.push_back(get(i - n + 1, i));
        }
    }

    // 對匹配的哈希值進行排序
    sort(matched.begin(), matched.end());
    int ans = 0;
    int last = -1;
    for(auto x : matched) {
        if(x == last) continue; // 排除重複的哈希值
        last = x;
        ans++; // 統計不同的匹配數
    }

    // 輸出結果
    cout << ans << "\n";
    return 0;
}
