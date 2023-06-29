#include <bits/stdc++.h>
using namespace std;


// Simple Recusrsive Approach --> match or not match approach
int solve(string &a, string &b, int idx1, int idx2) {
	if (idx1 < 0 || idx2 < 0 )return 0;

	// if both characters matches then move both the indexes by one.
	if (a[idx1] == b[idx2]) {
		return 1 + solve(a, b, idx1 - 1, idx2 - 1);
	}

	// move first idx by 1
	int x = solve(a, b, idx1 - 1, idx2);

	// or move second idx by 1.
	int y = solve(a, b, idx1, idx2 - 1) ;

	return max(x, y);

	// TC --> 2^n * 2^m
	// SC --> O(n+m)
}


int solveMemoWay(string a, string b, int idx1, int idx2, vector<vector<int>>&dp) {
	if (idx1 == 0 || idx2 == 0 )return 0;

	if (dp[idx1][idx2] != -1)return dp[idx1][idx2];

	// if both characters matches then move both the indexes by one.
	if (a[idx1 - 1] == b[idx2 - 1]) {
		return dp[idx1][idx2] = 1 + solveMemoWay(a, b, idx1 - 1, idx2 - 1, dp);
	}

	// move first idx by 1
	int x = solveMemoWay(a, b, idx1 - 1, idx2, dp);

	// or move second idx by 1.
	int y = solveMemoWay(a, b, idx1, idx2 - 1, dp) ;

	return dp[idx1][idx2] = max(x, y);

	// TC --> O(n*m) --> will visit every state only once.
	// SC --> O(n*m) + O(n+m) --> dp array and recursion stack space
}



int tabulationWay(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	// to accomodate the base case we have shifted the indexes by one place.

	//base case --> if idx1 == 0 or idx2 == 0, return 0.
	for (int j = 0; j <= m; j++)dp[0][j] = 0;
	for (int j = 0; j <= n; j++)dp[j][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[idx2 - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}

			else {
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}

		}
	}

	return dp[n][m];

	// TC --> O(n*m)
	// SC --> O(n*m) --> only dp array space required
}

int optimizedTabulationWay(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<int>prev(m + 1, 0), curr(m + 1, 0);
	prev[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[j - 1]) {
				curr[j] = 1 + prev[j - 1];
			}

			else {
				curr[j] = max(prev[j] , curr[j - 1]);
			}

		}
		prev = curr;
	}

	return prev[m];

	// TC --> O(n*m)
	// SC --> O(m) --> storing only 1D array.
}


int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	return solveMemoWay(text1, text2, n , m , dp);
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string a, b;
	cin >> a >> b;

	cout << longestCommonSubsequence(a, b) << endl;
}