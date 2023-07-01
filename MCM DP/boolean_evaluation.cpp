#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int solve(int i, int j, bool isTrue, string &exp) {
	if (i > j)return 0;
	if (i == j) {
		if (isTrue)return exp[i] == 'T';
		else return exp[i] == 'F';
	}


	ll ways = 0;
	for (int k = i + 1; k < j; k += 2) {
		// if we are searching for a falsy value then we have to give
		// isTrue as false.
		// lT = leftTrue , rT = rightTrue, lF = leftFalse, rF = rightFalse
		ll lT = solve(i, k - 1, 1, exp);
		ll lF = solve(i, k - 1, 0, exp);
		ll rT = solve(k + 1, j, 1, exp);
		ll rF = solve(k + 1, j, 0, exp);


		if (exp[k] == '&') {
			// if isTrue is 1 then we need truthy value on both sides.
			if (isTrue) ways = (ways + (lT * rT) % mod) % mod;

			// else if isTrue is 0, we need falsy value on either one side or both
			else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
		}

		else if (exp[k] == '|') {
			// if isTrue is 1, then we need truthy value on either side or both
			if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;

			// else if isTrue is 0, then we need false on both sides to make it false.
			// as (F|F) == F only.
			else ways = (ways + (lF * rF) % mod) % mod;
		}

		// if exp[k] == '^'
		else {
			// (T^T = F , T^F = T,  F^T = T, F^F = F);
			if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
			else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
		}
	}

	return ways;
}

int solveMemoWay(int i, int j, bool isTrue, string &exp, vector<vector<vector<int>>>&dp) {
	if (i > j)return 0;
	if (i == j) {
		if (isTrue)return exp[i] == 'T';
		else return exp[i] == 'F';
	}

	if (dp[i][j][isTrue] != -1)return dp[i][j][isTrue];

	ll ways = 0;
	for (int k = i + 1; k < j; k += 2) {
		// if we are searching for a falsy value then we have to give
		// isTrue as false.
		// lT = leftTrue , rT = rightTrue, lF = leftFalse, rF = rightFalse
		ll lT = solveMemoWay(i, k - 1, 1, exp, dp);
		ll lF = solveMemoWay(i, k - 1, 0, exp, dp);
		ll rT = solveMemoWay(k + 1, j, 1, exp, dp);
		ll rF = solveMemoWay(k + 1, j, 0, exp, dp);


		if (exp[k] == '&') {
			// if isTrue is 1 then we need truthy value on both sides.
			if (isTrue) ways = (ways + (lT * rT) % mod) % mod;

			// else if isTrue is 0, we need falsy value on either one side or both
			else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
		}

		else if (exp[k] == '|') {
			// if isTrue is 1, then we need truthy value on either side or both
			if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;

			// else if isTrue is 0, then we need false on both sides to make it false.
			// as (F|F) == F only.
			else ways = (ways + (lF * rF) % mod) % mod;
		}

		// if exp[k] == '^'
		else {
			// (T^T = F , T^F = T,  F^T = T, F^F = F);
			if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
			else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
		}
	}

	return dp[i][j][isTrue] = ways;
}

int tabulationWay(string &exp) {
	int n = exp.size();
	vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

	//base case
	for (int i = 0; i < n; i++) {
		if (exp[i] == 'T')dp[i][i][1] = 1;
		else if (exp[i] == 'F')dp[i][i][0] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			for (int isTrue = 1; isTrue >= 0; isTrue--) {
				// don't overwrite the base case values.
				if (i == j || i > j)continue;
				ll ways = 0;
				for (int k = i + 1; k < j; k += 2) {
					ll lT = dp[i][k - 1][1];
					ll lF = dp[i][k - 1][0];
					ll rT = dp[k + 1][j][1];
					ll rF = dp[k + 1][j][0];


					if (exp[k] == '&') {
						if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
						else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
					}

					else if (exp[k] == '|') {

						if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
						else ways = (ways + (lF * rF) % mod) % mod;
					}
					else {

						if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
						else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
					}
				}

				dp[i][j][isTrue] = ways;
			}
		}
	}

	return dp[0][n - 1][0];

}


int evaluateExp(string &exp) {
	// int n = exp.size();
	// vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
	// return solveMemoWay(0, n - 1, 1, exp, dp);

	return tabulationWay(exp);
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

	cout << evaluateExp(s) << endl;

}