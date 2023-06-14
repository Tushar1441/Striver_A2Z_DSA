#include <bits/stdc++.h>
using namespace std;


void solve(int idx, int k, vector<string> &ans, string bal) {
	if (idx == k) {
		ans.push_back(bal);
		return;
	}

	bal.push_back('0');
	solve(idx + 1, k, ans, bal);
	bal.pop_back();

	if (idx == 0  || (idx > 0 && bal[idx - 1] != '1')) {
		bal.push_back('1');
		solve(idx + 1, k, ans, bal);
	}
}


vector<string> generateString(int k) {
	vector<string> ans;
	string bal = "";
	solve(0, k, ans, bal);

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

	vector<string>ans = generateString(n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}


