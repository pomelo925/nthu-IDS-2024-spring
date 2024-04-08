//https://acm.cs.nthu.edu.tw/contest/2971/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    stack<int> st; string s;
    getline(cin, s);

    while(n--){
        getline(cin, s);
        
        if(s=="Undo") {if(!st.empty()) st.pop();}
        else if(s[0]=='+') st.push(stoi(s.substr(2)));
        else if(s[0]=='-') st.push(-stoi(s.substr(2)));
    }

    long long ans=0;
    int k=st.size();
    for(int i=0; i<k; i++){
        // cout << st.top() << " ";
        ans += st.top();
        st.pop();
    }

    cout << ans << "\n";
    return 0;
}