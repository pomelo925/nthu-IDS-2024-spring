// https://acm.cs.nthu.edu.tw/contest/2972/
// 超笨，直接列出所有字母再檢查，嚴重TLE

#include <bits/stdc++.h>
using namespace std;

void dfs(const string s, vector<bool> &visited, string &path, vector<string> &res){
  vector<string> permu;

  // 遍歷結束
  if(path.length() == s.length()){
    res.push_back(path);
    return;
  }
  
// dfs
  for(int i=0; i<s.length(); i++){
    // 已訪問，則跳過
    if(visited[i]) continue;

    // 遇重複字元，則跳過 
    if(i>0 && s[i]==s[i-1] && !visited[i-1]) continue;

    // 加入
    path.push_back(s[i]);
    visited[i]=true;
    dfs(s, visited, path, res);
    path.pop_back();
    visited[i]=false;
  }
}

vector<int> genNext(string s){
  vector<int> next(s.size(), 0);

  for(int i=1, len=0; i<s.size(); ){
    if(s[i] == s[len]) next[i++] = ++len;
    else if(len) len=next[len-1];
    else next[i++]=0;
  }
  
  return next;
}

bool kmp(const string &str, const string &haystack){
  // 生成 next 數組
  const vector<int> next = genNext(str);

  for(int i=0, j=0; i<haystack.size() && j<str.size(); ){
    // cout << i << " " << j  << endl;

    // 當前字元相同
    if((haystack[i] == str[j])){
      if(j == str.size()-1) return true;
      i++; j++;
    } 
    
    // 當前字元相異
    else if(j) j=next[j-1];
    else i++;
  }

  return false;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string needle, haystack;
  getline(cin, needle);
  getline(cin, haystack);

// DFS 前置作業
  sort(needle.begin(), needle.end());
  vector<bool> visited(needle.length(), false);
  string path;
  vector<string> res;
  dfs(needle, visited, path, res);

  // for(const auto &str : res) cout << str << endl;
  
  int ans=0;
  for(const auto &str : res) if(kmp(str, haystack)) ans+=1;

  cout << ans << endl;

  return 0;
}