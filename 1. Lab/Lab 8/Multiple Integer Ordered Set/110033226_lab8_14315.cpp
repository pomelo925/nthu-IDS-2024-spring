#include <iostream>
#include <set>
#include <map>
 
using namespace std;
 
int main() {
  int n, x;
  map<int, int>  mp;
  string op;

  cin >> n;

  while(n--) {
    cin >> op >> x;
    
    switch(op[0]) {
    case 'I':
      mp[x]++;
      cout << mp.size() << "\n";
      break;

    case 'D':
      if (mp.find(x) != mp.end()) {
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
      }
      cout << mp.size() << "\n";
      break;

    case 'C':
      if (mp.find(x) != mp.end()) cout << mp[x] << '\n';
      else cout << "0\n";
      break;

    case 'L':
      if (mp.lower_bound(x) != mp.end()) cout << (*mp.lower_bound(x)).first << "\n";
      else cout << "-1\n";
      break;

    case 'U':
        if (mp.upper_bound(x) != mp.end()) cout << (*mp.upper_bound(x)).first << "\n";
        else cout << "-1\n";
        break;

    default:
        break;
    }
  }
  return 0;
}