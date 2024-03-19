// https://acm.cs.nthu.edu.tw/contest/2951/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto &a:A) cin >> a;

    sort(A.begin(), A.end(), [](ll a, ll b){
        return a>b;
    });

    for(auto a:A)cout << a << " ";
    cout << endl;

    return 0;
}