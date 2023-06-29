#include <bits/stdc++.h>
using namespace std;


// to find the longest common substring length
// we have to do a slight change in the subsequences problem
// IMPORTANT->
// if at any index, s1[i] != s2[j] then dp[i][j] = 0;
// if s1[i] == s2[j] then dp[i][j] = 1 + dp[i-1][j-1].
int longestCommonSubstring(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));

	for (int j = 0; j <= m; j++)dp[0][j] = 0;
	for (int j = 0; j <= n; j++)dp[j][0] = 0;

	// initialise an answer variable to store the max length of the longest common substring
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}

			else {
				dp[i][j] = 0;
			}

			ans = max(ans, dp[i][j]);

		}
	}

	return ans;

	// TC --> O(n*m)
	// SC --> O(n*m) --> only dp array space required
}


// space optimisation using only a 1D array instead of 2D dp array
int optimizedTabulationWay(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<int>prev(m + 1, 0), curr(m + 1, 0);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[j - 1]) {
				curr[j] = 1 + prev[j - 1];
			}

			else {
				curr[j] = 0;
			}
			ans = max(ans, curr[j]);

		}
		prev = curr;
	}

	return ans;


	// TC --> O(n*m)
	// SC --> O(m) --> only 1D dp array space required
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

	cout << longestCommonSubstring(a, b) << endl;
}