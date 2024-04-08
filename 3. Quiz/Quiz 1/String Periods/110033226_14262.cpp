#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1E9 + 9;
constexpr int A = 998244353;

constexpr int MAX = 1E6 + 5;

int power[MAX], hsh[MAX];

int get(int i, int j){
    return hsh[j]-(1LL*hsh[i-1]*power[j-i+1]%MOD+MOD)%MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    const int N = s.size();

// power
    power[1]=1;
    for(int i=2; i<N; i++) power[i] = 1LL*power[i-1]*A%MOD;


// hash fucntion
    hsh[1] = s[0]-'a';
 	for(int i=2; i<N; i++) hsh[i]=hsh[i-1]*power[i]+(s[i]-'a');

    int ALL = hsh[N-1];

// 檢查長度2以上
    for(int len=1; len<N; len++){
        int curr = len;
        for(int t=2; curr*t<N; t++, curr*=t){
            if(!hsh[len] == get(curr+1,curr*t)) break;
            else cout << "ya ";
        }

        cout << len << "\t" << curr << '\n';

        // 還沒檢查到字尾
        if(curr+len<N) continue;
        
        // 剛好到字尾
        if(curr == N){
            if(hsh[curr] == hsh[N]) cout << len << " ";
        } else {
            if(hsh[N%len] == get(N-N%len-1,N)) cout << len << " ";
        }

    }

    return 0;
}
