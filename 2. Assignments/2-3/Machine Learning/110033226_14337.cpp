// https://acm.cs.nthu.edu.tw/contest/3020/

#include <bits/stdc++.h>
using namespace std;

typedef vector<tuple<int,int,bool>> vpiib;
typedef tuple<int,int,bool> piib;

bool cpr(const piib& a, const piib& b) {
    if (get<1>(a) == get<1>(b))  return get<0>(a) < get<0>(b);
    return get<1>(a) > get<1>(b);
}

int main() {
  int C, S;
  cin >> C >> S;
  
  vpiib course(C);
  vector<int> student(S,0);

  for(auto &[start,end,avail]:course){
    cin >> start >> end;
    avail=true;
  }
  
  sort(course.begin(), course.end(), cpr);

  int total=0;
  for(auto &lst:student){
    for(auto &[start, end, avail]:course){
      if(!avail) continue;
      if(end>lst){
        total++; 
        lst=start;
        avail=false;
      }
    }
  }

  cout << total << endl;
  return 0;
}