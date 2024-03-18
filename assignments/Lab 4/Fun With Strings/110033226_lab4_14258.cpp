// https://acm.cs.nthu.edu.tw/contest/2972/
#include <bits/stdc++.h>

using namespace std;

void fun(const string& s, vector<string>& vs){
  char cmd;
  int a, b;

  istringstream iss(s);
  iss >> cmd >> a >> b;

  if(cmd == 'E'){
    if(vs[a-1] == vs[b-1]) cout << "Y\n";
    else cout << "N\n";
  }
  else if(cmd == 'C') vs[a-1]=string(vs[a-1] + vs[b-1]);
}

int main(){
  int n, m;
  cin >> n >> m;

  vector<string> vs(n);
  for(auto& s : vs) cin >> s;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while(m--){
    string s;
    getline(cin, s);
    if(!s.empty()) fun(s, vs);
  }

  return 0;
}