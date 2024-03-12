// https://acm.cs.nthu.edu.tw/contest/2956/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isCorrect(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[') st.push(c);
        else {
            // If it's a closing bracket and the stack is empty or doesn't match the top, it's incorrect
            if (st.empty() || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '[')) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // Ignore the newline character after reading n

    for (int i=0; i<n; i++) {
        string s;
        getline(cin, s); // Read the entire line since strings may contain spaces
        if(i==n-1) cout << (isCorrect(s)? "Y" : "N");
        else cout << (isCorrect(s)? "Y\n" : "N\n");
    }

    return 0;
}
