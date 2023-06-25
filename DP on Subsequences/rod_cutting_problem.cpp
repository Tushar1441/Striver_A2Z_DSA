#include <bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int>&arr, int units) {
	if (units == 0)return 0;
	if (idx ==  0) {
		// at 0th index all remaining units costs -> n*arr[0]
		return units * arr[0];
	}

	//pick
	int pick = -1e9;
	if (units >= idx + 1) pick = solve(idx, arr, units - idx - 1) + arr[idx];

	//not pick'
	int notpick = solve(idx - 1, arr, units);

	return max(pick, notpick);
}


int solveMemoWay(int idx, vector<int>&arr, int units, vector<vector<int>>&dp) {

	if (idx ==  0) {
		// at 0th index all remaining units costs -> n*arr[0]
		return units * arr[0];
	}

	if (dp[idx][units] != -1)return dp[idx][units];
	//pick
	int pick = -1e9;
	if (units >= idx + 1) pick = solveMemoWay(idx, arr, units - idx - 1, dp) + arr[idx];

	//not pick'
	int notpick = solveMemoWay(idx - 1, arr, units, dp);

	return dp[idx][units] = max(pick, notpick);

}


int tabulationWay(vector<int> &price, int n) {
	vector<vector<int>>dp(n, vector<int>(n + 1, 0));

	// base case
	for (int i = 0; i <= n; i++) {
		dp[0][i] = i * arr[0] ;
	}

	for (int idx = 1; idx < n; idx++) {

		for (int units = 0; units <= n; units++) {
			int pick = -1e9;
			if (units >= idx + 1)pick = dp[idx][units - idx - 1] + arr[idx];

			//not pick'
			int notpick = dp[idx - 1][units];

			dp[idx][units] = max(pick, notpick);
		}
	}

	return dp[n - 1][n];
}

int optimizedTabulationWay(int n, int w, vector<int> &profit, vector<int> &weight) {
	vector<int>prev(n + 1, 0), curr(n + 1, 0);

	// base case
	for (int i = 0; i <= n; i++) {
		prev[i] = i * price[0] ;
	}

	for (int idx = 1; idx < n; idx++) {

		for (int units = 0; units <= n; units++) {
			int pick = -1e9;
			if (units >= idx + 1)pick = curr[units - idx - 1] + price[idx];

			//not pick'
			int notpick = prev[units];

			curr[units] = max(pick, notpick);
		}

		prev = curr;
	}

	return  prev[n];
}

int maxCost(vector<int> &price, int n)
{
	//Write your code here
	vector<vector<int>>dp(n, vector<int>(n + 1, -1));
	return solveMemoWay(n - 1, price, n, dp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;

	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << maxCost(arr, n) << endl;

}