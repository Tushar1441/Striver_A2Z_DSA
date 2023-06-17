#include <bits/stdc++.h>
using namespace std;

void solve( string num, int target, string currentNum, long long prev, long long curr, vector<string>&ans ) {
	if (num.empty()) {
		if (curr == target) {
			ans.push_back(currentNum);
		}
		return;
	}

	for (int i = 1; i <= num.length(); i++) {
		string curr_num = num.substr(0, i);

		// check for leading zeroes
		if (num[0] == '0' && i > 1)return;

		// if the currentNum is empty no need to add operators
		long long num_val = stoll(curr_num);
		if (currentNum.empty()) {
			solve(num.substr(i), target, curr_num, num_val, curr + num_val, ans);
		} else {
			solve(num.substr(i), target, currentNum + "+" + curr_num, num_val, curr + num_val, ans);
			solve(num.substr(i), target, currentNum + "-" + curr_num, -num_val, curr - num_val, ans);
			solve(num.substr(i), target, currentNum + "*" + curr_num, prev * num_val, curr - prev + prev * num_val, ans);
		}
	}

}


vector<string> addOperators(string num, int target) {
	vector<string> ans;
	solve(num, target, "", 0, 0, ans);
	return ans;
	// The time complexity of the solution is O(4^N), where N is the number of digits
	// in the input number, because each digit can have four possibilities
	// (no operator, +, -, or *).
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	string s;
	cin >> s >> n;

	vector<string> ans = addOperators(s, n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

}


