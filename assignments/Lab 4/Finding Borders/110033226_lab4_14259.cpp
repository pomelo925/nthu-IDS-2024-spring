// https://acm.cs.nthu.edu.tw/contest/2972/
#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string& s) {
    int n = s.length();
    vector<int> lps(n, 0); // 最長相同前後綴長度
    for (int i=1, len=0; i<n;){
        if (s[i] == s[len]) lps[i++] = ++len;
        else if (len)len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<int> lps = kmp(s);
    int n = s.length();
    vector<int> borders;

    // 將所有邊界長度添加到一個陣列中
    for (int len=lps[n-1]; len>0; len=lps[len-1]) borders.push_back(len);

    sort(borders.begin(), borders.end());

    for (int i=0; i<borders.size(); i++) {
        if (i==borders.size()-1) cout << borders[i] << endl;
        else cout << borders[i] << " ";
    }
    return 0;
}
