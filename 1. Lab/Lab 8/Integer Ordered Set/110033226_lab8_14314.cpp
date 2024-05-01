#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, x;
  string op;
  set<int> s;
  cin >> n;
  
  while(n--) {
    cin >> op >> x;
    
    switch(op[0]) {
    case 'I':
        if (s.find(x) == s.end()) s.insert(x);
        cout << s.size() << "\n";
        break;

    case 'D':
        if (s.find(x) != s.end()) s.erase(x);
        cout << s.size() << "\n";
        break;

    case 'S':
        if (s.find(x) != s.end()) cout << "YES\n";
        else cout << "NO\n";
        break;

    case 'L':
        if (s.lower_bound(x) != s.end()) cout << *s.lower_bound(x) << "\n";
        else cout << "-1\n";
        break;

    case 'U':
        if (s.upper_bound(x) != s.end()) cout << *s.upper_bound(x) << "\n";
        else cout << "-1\n";
        break;

    default:
        break;
    }
  }
  return 0;
}