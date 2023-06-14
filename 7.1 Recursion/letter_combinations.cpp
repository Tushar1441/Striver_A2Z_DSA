#include <bits/stdc++.h>
using namespace std;


void solve(int idx, string mp[], string digits, vector<string> &ans, string bal) {
	if (idx == digits.size()) {
		ans.push_back(bal);
		return;
	}


	int num = digits[idx] - '0';
	string val = mp[num];

	for (int i = 0; i < val.length(); i++) {
		bal.push_back(val[i]);
		solve(idx + 1, mp, digits, ans, bal);
		bal.pop_back();

	}


	// TC --> O(k^n), here k is the average number of choices on every digit.
	// SC --> O(k^n)
}


vector<string> letterCombinations(string digits) {
	vector<string> ans;
	if (digits.length == 0)return ans;
	string bal = "";
	string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int n = digits.length();
	solve(0, mp, digits, ans, bal);

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

	vector<string>ans = letterCombinations(n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}


