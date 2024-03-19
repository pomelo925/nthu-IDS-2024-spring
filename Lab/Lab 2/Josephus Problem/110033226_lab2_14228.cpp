#include <bits/stdc++.h>

using namespace std;

void josephus(int n){
  queue<int> q; //FIFO
  for(int i=1; i<=n; i++) q.push(i);

  // 把頭複製到尾，刪去頭，印此時的頭，再刪去。
  while(!q.empty()){
    q.push(q.front());
    q.pop();
    if(q.size()>1) cout << q.front() << " ";
    else cout << q.front();
    q.pop();
  }
  return;
}

int main(){
  int n;
  cin >> n;
  josephus(n);
  return 0;
}