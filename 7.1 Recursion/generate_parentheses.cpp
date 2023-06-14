#include <bits/stdc++.h>
using namespace std;


void solve(int open, int close, vector<string> &ans, string bal) {
	if (open == 0 && close == 0) {
		ans.push_back(bal);
		return;
	}

	if (open != 0) {
		string bal1 = bal;
		bal1.push_back('(');
		solve(open - 1, close, ans, bal1);
	}

	if (close != open) {
		string bal2 = bal;
		bal2.push_back(')');
		solve(open, close - 1, ans, bal2);
	}
}


vector<string> generateParantheses(int n) {
	vector<string> ans;
	int open = n;
	int close = n;
	string bal = "";
	solve(open, close, ans, bal);

	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	cin >> n ;

	vector<string>ans = generateParantheses(n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}


