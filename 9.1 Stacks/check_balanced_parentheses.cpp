#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
	stack<char>st;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			if (st.top() == '(')st.pop();
		}

		else if (s[i] == '}') {
			if (st.top() == '{')st.pop();
		}

		else if (s[i] == ']') {
			if (st.top() == '[')st.pop();
		}

		else st.push(s[i]);
	}

	return st.empty();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s;
	cin >> s;
	cout << isValid(s) << endl;
}