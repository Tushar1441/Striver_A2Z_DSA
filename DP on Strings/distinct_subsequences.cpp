#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// simple recurrence solution
int solve(string &s, string &t, int idx1, int idx2) {
	// if second string is exhausted then return 1.
	if (idx2 == 0)return 1;

	// if first string is exhausted return 0.
	if (idx1 == 0)return 0;


	// if characters matches --> there are two options
	// move i and j both or move only i.
	if (s[idx1 - 1] == t[idx2 - 1]) {
		int leaveOne = solve(s, t, idx1 - 1, idx2 - 1);
		int stay = solve(s, t, idx1 - 1, idx2);

		return (leaveOne + stay) % mod;
	}

	// if char not matches move only i.
	else {
		return solve(s, t, idx1 - 1, idx2);
	}

	// TC --> O(2^n * 2^m)
	// SC --> O(n+m)
}


int solveMemoWay(string &s, string &t, int idx1, int idx2, vector<vector<int>>&dp) {
	// if second string is exhausted then return 1.
	if (idx2 == 0)return 1;

	// if first string is exhausted return 0.
	if (idx1 == 0)return 0;

	if (dp[idx1][idx2] != -1)return dp[idx1][idx2];

	// if characters matches --> there are two options
	// move i and j both or move only i.
	if (s[idx1 - 1] == t[idx2 - 1]) {
		int leaveOne = solveMemoWay(s, t, idx1 - 1, idx2 - 1, dp);
		int stay = solveMemoWay(s, t, idx1 - 1, idx2, dp);

		return dp[idx1][idx2] = (leaveOne + stay) % mod;
	}

	// if char not matches move only i.
	else {
		return dp[idx1][idx2] =  solveMemoWay(s, t, idx1 - 1, idx2, dp);
	}

	// TC --> O(n*m)
	// SC --> O(n*m) + O(n+m)
}

int tabulationWay(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	// base case
	for (int i = 0; i <= n; i++)dp[i][0] = 1;
	for (int j = 1; j <= m; j++)dp[0][j] = 0;

	// explore all the states
	for (int idx1 = 1; idx1 <= n; idx1++) {

		for (int idx2 = 1; idx2 <= m; idx2++) {
			// copy the recurrence

			if (s[idx1 - 1] == t[idx2 - 1]) {
				dp[idx1][idx2] = (dp[idx1 - 1][idx2 - 1] + dp[idx1 - 1][idx2]) % mod;
			}

			// if char not matches move only i.
			else dp[idx1][idx2] =  dp[idx1 - 1][idx2];

		}
	}

	return dp[n][m];

	//TC --> O(n*m)
	// SC --> O(n*m)
}

int optimizedTabulationWay(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<int>prev(m + 1, 0), curr(m + 1, 0);

	prev[0] = 1;

	// explore all the states
	for (int idx1 = 1; idx1 <= n; idx1++) {
		curr[0] = 1;
		for (int idx2 = 1; idx2 <= m; idx2++) {
			// copy the recurrence

			if (s[idx1 - 1] == t[idx2 - 1]) {
				curr[idx2] = (prev[idx2 - 1] + prev[idx2]) % mod;
			}

			// if char not matches move only i.
			else curr[idx2] =  prev[idx2];

		}
		prev = curr;

	}

	return prev[m];

	//TC --> O(n*m)
	// SC --> O(m)

}


int distinctSubsequences(string s, string t) {
	// int n = s.size();
	// int m = t.size();
	// vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	// return solveMemoWay(s, t, n, m, dp);

	return optimizedTabulationWay(s, t);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string a = "rabbbit";
	string b = "rabbit";

	cout << distinctSubsequences(a, b);
}

