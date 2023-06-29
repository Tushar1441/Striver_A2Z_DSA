#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// simple recurrence solution
int solve(string &s, string &t, int idx1, int idx2) {
	// base case
	// if string 1 is exhausted, then we have to insert remaining string2 to string1.
	if (idx1 == 0)return idx2;
	// if string 2 is exhausted, then we have to delete remaining string1 characters.
	if (idx2 == 0)return idx1;


	// possible states

	//1) if characters matches, no operation is needed.
	if (s[idx1 - 1] == t[idx2 - 1]) {
		return 0 + solve(s, t, idx1 - 1, idx2 - 1);
	}


	// else there are three possible operations
	else {

		// insert a hypothetical char into string1 at last.
		// the inserted char will match t[idx2-1] so, only move index2.
		int insert = 1 + solve(s, t, idx1, idx2 - 1);

		//delete a char
		// hypothetically delete a char from string1 and move it's index forward.
		int deleteChar = 1 + solve(s, t, idx1 - 1, idx2);


		// replace a char
		// hypothetically replace the string1[idx1] to string2[idx2] and move both the pointers
		int replace = 1 + solve(s, t, idx1 - 1, idx2 - 1);


		// return the min of the three.
		return min(insert, min(deleteChar, replace));
	}

	// TC --> O(3^n)
	// SC --> O(n+m)
}



int solveMemoWay(string &s, string &t, int idx1, int idx2, vector<vector<int>>&dp) {

	if (idx1 == 0)return idx2;
	if (idx2 == 0)return idx1;

	if (dp[idx1][idx2] != -1)return dp[idx1][idx2];

	if (s[idx1 - 1] == t[idx2 - 1]) {
		return dp[idx1][idx2] = solveMemoWay(s, t, idx1 - 1, idx2 - 1, dp);
	}
	else {

		int insert = 1 + solveMemoWay(s, t, idx1, idx2 - 1, dp);
		int deleteChar = 1 + solveMemoWay(s, t, idx1 - 1, idx2, dp);
		int replace = 1 + solveMemoWay(s, t, idx1 - 1, idx2 - 1, dp);

		return dp[idx1][idx2] = min(insert, min(deleteChar, replace));
	}

	// TC --> O(n*m)
	// SC --> O(n*m) + O(n+m)
}

int tabulationWay(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	// base case
	for (int i = 0; i <= n; i++)dp[i][0] = i;
	for (int j = 1; j <= m; j++)dp[0][j] = j;

	// explore all the states
	for (int idx1 = 1; idx1 <= n; idx1++) {

		for (int idx2 = 1; idx2 <= m; idx2++) {
			// copy the recurrence

			if (s[idx1 - 1] == t[idx2 - 1]) {
				dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
			}
			else {

				dp[idx1][idx2] =
				    1 + min(dp[idx1][idx2 - 1], min(dp[idx1 - 1][idx2], dp[idx1 - 1][idx2 - 1]));
			}

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

	// base case
	for (int j = 0; j <= m; j++) prev[j] = j;


	// explore all the states
	for (int idx1 = 1; idx1 <= n; idx1++) {
		curr[0] = idx1;
		for (int idx2 = 1; idx2 <= m; idx2++) {
			// copy the recurrence

			if (s[idx1 - 1] == t[idx2 - 1]) {
				curr[idx2] = prev[idx2 - 1];
			}
			else {
				curr[idx2] = 1 + min(curr[idx2 - 1], min(prev[idx2], prev[idx2 - 1]));
			}

		}
		prev = curr;
	}

	return prev[m];

	//TC --> O(n*m)
	// SC --> O(m)

}


int editDistance(string s, string t) {
	int n = s.size();
	int m = t.size();
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
	string a = "horse";
	string b = "ros";

	cout << editDistance(a, b);
}

