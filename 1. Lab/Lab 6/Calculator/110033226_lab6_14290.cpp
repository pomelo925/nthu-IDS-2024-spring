#include <bits/stdc++.h>
using namespace std;

string ShuntingYardAlgo(string inorder) {
    map<char, int> priority {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };
    stack<char> operator_stack;
    string postorder;

    for(auto i : inorder) {
        if(i >= 'A' and i <= 'Z') postorder.push_back(i);
        else if(i == '+' || i == '-' || i == '*' || i == '/') {
            while(operator_stack.size() and 
                priority[operator_stack.top()] >= priority[i] and 
                operator_stack.top() != '(') 
            {
                postorder.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(i);
        }
        else if(i == '(') operator_stack.push(i);
        else if(i == ')') {
            while(operator_stack.top() != '(') {
                postorder.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
    }
    while(operator_stack.size()) {
        postorder.push_back(operator_stack.top());
        operator_stack.pop();
    }
    return postorder;
}

void solve(const string &post) {
    vector<int> value(5);
    for(int i = 0; i < 5; ++i) cin >> value[i];
    stack<int> st;
    for(auto i : post) {
        if(i >= 'A' and i <= 'Z') st.push(value[i - 'A']);
        
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            swap(a, b);
            int ans;
            if(i == '+') ans = a + b;
            else if(i == '-') ans = a - b;
            else if(i == '*') ans = a * b;
            else ans = a / b;
            st.push(ans);
        }
    }
    cout << st.top();
}

int main() {
    string s; cin >> s;
    string post = ShuntingYardAlgo(s);

    int t; cin >> t;
    for(int i=t; i>0; i--){

		solve(post);
		if(i>1) cout << '\n';
	} 
}