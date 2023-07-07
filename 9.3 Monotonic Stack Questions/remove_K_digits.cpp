#include <bits/stdc++.h>
using namespace std;


string removeKdigits(string num, int k) {
	stack<int>st;
	int i = 0;
	while (i < num.length()) {
		while (k > 0 && !st.empty() && st.top() > (int)num[i]) {
			k--;
			st.pop();
		}

		st.push((int)num[i]);
		i++;
	}

	while (k > 0) {
		st.pop();
		k--;
	}

	// copy the stack characters to a new answer string;
	string ans = "";
	while (!st.empty()) {
		ans += (char)st.top();
		st.pop();
	}

	// reverse the stack characters
	reverse(ans.begin(), ans.end());


	// Edge Case --> remove any leading zeroes
	for (int i = 0; i < ans.length(); i++) {
		// check for the first non-zero character
		if (ans[i] != '0') {
			// return the remaining string
			string res = ans.substr(i);
			return res;
		}
	}

	return "0";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int k;
	string num;
	cin >> num >> k;
	cout << removeKdigits(num, k) << endl;
}
