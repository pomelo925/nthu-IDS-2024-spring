//https://acm.cs.nthu.edu.tw/contest/3004/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	// priority_queue<int, vector<int>, greater<int>> pq;
	multiset<int> s;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			// push
			int x;
			cin >> x;
			// pq.push(x);
			s.insert(x);
		} else if(type == 2) {
			// pop
			// if(!pq.empty()) {
			// 	pq.pop();
			// }
			if(!s.empty()) {
				s.erase(s.begin());
			}
		} else {
			// if(pq.empty()) {
			// 	cout << "EMPTY\n";
			// } else {
			// 	cout << pq.top() << "\n";
			// }
			if(s.empty()) {
				cout << "EMPTY\n";
			} else {
				cout << *s.begin() << "\n";
			}
		}
	}
	return 0;
}
