#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach --> Using Recursion either jump 1 or jump 2 stairs.
int countWays1(int n) {
	if (n <= 0) {
		if (n == 0)return 1;
		else return 0;
	}

	return countWays1(n - 1) + countWays1(n - 2);
}


// using memoization
int countWays2(int n, vector<int>&dp) {
	if (n <= 1)return 1;

	if (dp[n] != -1)return dp[n];

	return dp[n] = countWays2(n - 1, dp) + countWays2(n - 2, dp);
}


// Bottom Up Approach
// tabulation with space optimisation
int countWays(int n) {
	if (n <= 2)return n;

	int prev1 = 2;
	int prev2 = 1;

	for (int i = 3; i <= n; i++) {
		int curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}

	return prev1;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	cin >> n;
	vector<int>dp(n + 1, -1);
	cout << countWays(n) << endl;

}