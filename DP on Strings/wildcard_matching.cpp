#include <bits/stdc++.h>
using namespace std;

bool solve(int idx1, int idx2, string &s, string &p) {

	// if pattern is completely exhausted.
	if (idx2 < 0) {
		// if text is also exhausted, then return true, else return false.
		return (idx1 < 0);
	}

	// if text is exhausted first, then check if the pattern conatins leading '*'
	// because they can be replaced as empty strings.
	if (idx1 < 0 && idx2 >= 0) {
		for (int i = 0; i <= idx2; i++) {
			if (p[i] != '*')return false;
		}
		return true;
	}

	// explore all possible states
	// if the characters matches or pattern[idx2] = '?', then move forward
	if (s[idx1] == p[idx2] || p[idx2] == '?') {
		return solve(idx1 - 1, idx2 - 1, s, p);
	}

	// if pattern[idx2] == '*',then we can return true.
	if (p[idx2 - 1] == '*') {
		return solve(idx1 , idx2 - 1, s, p) | solve(idx1 - 1, idx2, s, p);
	}

	else return false;
}

bool solveMemoWay(int idx1, int idx2, string &s, string &p, vector<vector<int>>&dp) {

	if (idx2 == 0) return (idx1 == 0);

	if (idx1 == 0 && idx2 > 0) {
		for (int i = 1; i <= idx2; i++) {
			if (p[i - 1] != '*')return 0;
		}
		return 1;
	}

	if (dp[idx1][idx2] != -1)return dp[idx1][idx2];

	if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?') {
		return dp[idx1][idx2] = solveMemoWay(idx1 - 1, idx2 - 1, s, p, dp);
	}

	if (p[idx2 - 1] == '*') {
		return dp[idx1][idx2] = solveMemoWay(idx1 , idx2 - 1, s, p, dp) | solveMemoWay(idx1 - 1, idx2, s, p, dp);
	}

	else return dp[idx1][idx2] = 0;
}

bool isAllStars(string & S1, int i) {

	// S1 is taken in 1-based indexing

}

bool tabulationWay(string text, string pattern) {
	int n = text.size();
	int m = pattern.size();

	vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, 0));

	//base case
	dp[0][0] = 1;

	for (int i = 1; i <= m; i++) {
		bool flag = true;
		for (int j = 1; j <= i; j++) {
			if (pattern[j - 1] != '*') {
				flag = false;
				break;
			}
		}

		dp[0][i] = flag;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// copy the recurrence
			if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
				dp[i][j] = dp[i - 1][j - 1];
			}

			else if (pattern[j - 1] == '*') {
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			}

			else dp[i][j] = 0;
		}
	}

	return dp[n][m];
}

bool optimizedTabulationWay(string text, string pattern) {
	int n = text.size();
	int m = pattern.size();

	vector<bool>prev(m + 1, 0), curr(m + 1, 0);

	//base case
	prev[0] = 1;

	for (int i = 1; i <= m; i++) {
		bool flag = true;
		for (int j = 1; j <= i; j++) {
			if (pattern[j - 1] != '*') {
				flag = false;
				break;
			}
		}

		prev[i] = flag;
	}

	for (int i = 1; i <= n; i++) {
		// curr[0] = 1;
		for (int j = 1; j <= m; j++) {
			// copy the recurrence
			if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
				curr[j] = prev[j - 1];
			}

			else if (pattern[j - 1] == '*') {
				curr[j] = curr[j - 1] | prev[j];
			}

			else curr[j] = 0;
		}
		prev = curr;
	}

	return prev[m];
}


bool isMatch(string s, string p) {
	// int n = s.length();
	// int m = p.length();
	// vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	// return solveMemoWay(n - 1, m - 1, s, p, dp);

	return optimizedTabulationWay(s, p);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string a = "ca";
	string b = "*a";

	cout << isMatch(a, b);
}
