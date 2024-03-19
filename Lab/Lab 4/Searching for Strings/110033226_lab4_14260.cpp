// https://acm.cs.nthu.edu.tw/contest/2972/
#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

umsi sub; // 儲存已配對過的子字串

// 檢查 needle 和 window 各自元數量是否相等
bool same(umci &nee, umci &window, string s){
  for(auto &n:nee){
    auto it = window.find(n.first);
    if(it == window.end() || it->second != n.second) return false;
  }

  for(auto &w:window){
    auto it = nee.find(w.first);
    if(it == nee.end() || it->second != w.second) return false;
  }

// 檢查此子字串是否已出現過
  if(sub.count(s)) return false;
  sub[s]++;
  return true;  
}


int numOfSubstring(const string &needle, const string &haystack){
  int ans=0;
  const int n=needle.size(), m=haystack.size();

  umci nee, window;

// 初始化 nee 和 window
  for(auto c:needle) nee[c]++;
  for(int i=0; i<n; i++) window[haystack[i]]++;
  
// 滑動窗口 window slide
  for(int i=0, j=n-1; j<m; ){
    if(same(nee, window, haystack.substr(i,n))) ans+=1;

    if(j == m-1) break;

    window[haystack[i++]]--;
    window[haystack[++j]]++;
    
  // 如果字元數量為零則刪除
    if(window[haystack[i-1]]==0) window.erase(haystack[i-1]);
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string needle, haystack;
  getline(cin, needle);
  getline(cin, haystack);
  
  cout << numOfSubstring(needle, haystack);
  cout << "\n";
  return 0;
}