#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int start, int end) {
	while (start <= end) {
		if (s[start++] != s[end--])return false;
	}

	return true;
}

void solve(int idx, vector<string> &ds, vector<vector<string>>&ans, string s) {
	if (idx == s.size()) {
		ans.push_back(ds);
		return;
	}

	for (int i = idx; i < s.size(); ++i) {
		if (isPalindrome(s, idx, i)) {
			ds.push_back(s.substr(idx, i - idx + 1));
			solve(i + 1, ds, ans, s);
			ds.pop_back();
		}
	}
}


vector<vector<string>> partition(string s) {
	vector<string> ds;
	vector<vector<string>>ans;
	string bal = "";
	solve(0, ds, ans, s);
	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string n;
	cin >> n ;

	vector<vector<string>>ans = partition(n);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}


