// https://acm.cs.nthu.edu.tw/contest/2951/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cpr(const int &a, const int &b){
    return a < b;
}

int main(){
    size_t n, m;
    cin >> n >> m;
    vector<ll> A(n);
    vector<ll> Q(m);

    for(auto &a:A) cin >> a;
    for(auto &q:Q) cin >> q;

    sort(A.begin(), A.end());

    for(auto ele:Q){
        if(binary_search(A.begin(), A.end(), ele)) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}