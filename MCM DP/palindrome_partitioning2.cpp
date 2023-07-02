#include <bits/stdc++.h>
using namespace std;

// helper funtion to check if string is palindrome.
bool isPalindrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

// Recursive Backtracking Solution.
int solve(int i, int n, string s) {
	if (i == n)return 0;

	int mini = 1e9;
	for (int j = i; j < n; j++) {
		if (isPalindrome(s, i, j)) {
			int cost = 1 + solve(j + 1, n, s);
			mini = min(mini, cost);
		}
	}
	return mini;
}

int solveMemoWay(int i, int n, string s, vector<int>&dp) {
	if (i == n)return 0;
	if (dp[i] != -1)return dp[i];

	int mini = 1e9;
	for (int j = i; j < n; j++) {
		if (isPalindrome(s, i, j)) {
			int cost = 1 + solveMemoWay(j + 1, n, s, dp);
			mini = min(mini, cost);
		}
	}
	return dp[i] = mini;
}

int tabulationWay(string s) {
	int n = s.size();
	vector<int>dp(n + 1, -1);

	dp[n] = 0;

	for (int i = n - 1; i >= 0; i--) {
		int mini = 1e9;
		for (int j = i; j < n; j++) {
			if (isPalindrome(s, i, j)) {
				int cost = 1 + dp[j + 1];
				mini = min(mini, cost);
			}
		}
		dp[i] = mini;
	}

	return dp[0] - 1;
}



int minCut(string s) {
	int n = s.size();
	vector<int>dp(n + 1, -1);

	// If we carefully observe, we can notice that our function is actually
	// counting an extra partition at the end of the string in each case.
	// For example, the given string is “abcd”. After doing a partition after ‘c’
	// the function will check if a partition can be done after ‘d’ to check
	// if the last substring i.e. ‘d’ itself is a palindrome.
	// For that our function will return 4 as the answer, instead of the actual answer is 3.

	// So, our actual answer will be (number of partitions returned by the function – 1).
	// return solveMemoWay(0, n, s, dp) - 1;

	return tabulationWay(s);
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

	cout << minCut(s) << endl;

}