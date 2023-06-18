#include <bits/stdc++.h>
using namespace std;

// using memoization
int fib1(int n, vector<int>&dp) {
	if (n <= 1)return n;

	if (dp[n] != -1)return dp[n];
	return (dp[n] = fib1(n - 1, dp) + fib1(n - 2, dp));

	// TC --> O(n)
	// SC --> O(n) + O(n), one for recursion stack space and other for dp array
}


// using tabulation
int fib2(int n, vector<int> &dp) {

	dp[0] = 0;
	dp[1] = 1;
	// doing bottom up approach.
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];

	// TC --> O(n)
	// SC --> no recursion space is used so --> O(n) only for dp array.
}


// space optimisation of the tabulation solution.
// we only need previous two fib values, so just store them in variables.
int fib(int n) {
	if (n <= 1)return n;

	int prev2 = 0;
	int prev = 1;


	// storing fib(n-1) and fib(n-2) into prev and prev2.
	for (int i = 2; i <= n; i++) {
		int curr = prev + prev2;
		prev2 = prev;
		prev = curr;

	}

	return prev;
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

	// initialise a dp array
	// int dp[n + 1];

	// initialise all values as -1;
	// memset(dp, -1, sizeof dp);

	// we can use vectors for dp also
	vector<int>dp(n + 1, -1);

	// calling the function
	cout << fib(n) << endl;

}