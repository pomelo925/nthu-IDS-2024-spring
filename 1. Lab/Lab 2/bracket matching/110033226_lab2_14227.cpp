// https://acm.cs.nthu.edu.tw/contest/2956/
#include <bits/stdc++.h>
using namespace std;

string s;

bool correct(const string &s){
  stack<char> st;

  for(auto c:s){
    if(c=='[' || c=='(') st.push(c);
    else{
      if(st.empty()) return false;
      if(c==')' && st.top()!='(') return false;
      if(c==']' && st.top()!='[') return false;
      st.pop();
    }
  }

  return st.empty();
}

int main(){
  int n;
  cin >> n;
  cin.ignore();

  while(n--){
    getline(cin, s);
    if(n>0) cout << (correct(s)? "Y\n":"N\n");
    else cout << (correct(s)? "Y":"N");
  }

  return 0;
}