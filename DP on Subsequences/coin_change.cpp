#include <bits/stdc++.h>
using namespace std;


int solve(int idx, vector<int>arr, int target) {
	if (target == 0)return 0;
	if (idx == 0) {
		if (target % arr[idx] == 0) return (target / arr[0]);
		return 1e9;
	}

	//pick
	int pick = 1e9;
	if (target >= arr[idx]) pick = solve(idx, arr, target - arr[idx]) + 1;

	// not pick
	int notpick = solve(idx - 1, arr, target);

	return min(pick, notpick);

	//TC --> O(2^t) here t is the max target.
	// SC --> O(n)
}


int solveMemoWay(int idx, vector<int>arr, int target, vector<vector<int>>&dp) {
	if (target == 0)return 0;
	if (idx == 0) {
		if (target % arr[idx] == 0) return (target / arr[0]);
		return 1e9;
	}

	if (dp[idx][target] != -1)return dp[idx][target];

	//pick
	int pick = 1e9;
	if (target >= arr[idx]) pick = solveMemoWay(idx, arr, target - arr[idx], dp) + 1;

	// not pick
	int notpick = solveMemoWay(idx - 1, arr, target, dp);


	return dp[idx][target]  = min(pick, notpick);

	//TC --> O(n*t) here t is the max target.
	// SC --> O(n) + O(n*t)
}


int tabulationWay(vector<int>arr, int x) {
	int n = arr.size();
	vector<vector<long>> dp(n, vector<int>(x + 1, 0));

	// base case
	for (int i = 0; i <= x; i++) {
		if (i % arr[0] == 0) dp[0][i] = i / arr[0];
		else dp[0][i] = 1e9;
	}


	//possible states
	for (int idx = 1; idx < n; idx++) {
		for (int target = 0; target <= x; target++) {

			int pick = 1e9;
			if (target >= arr[idx]) pick = dp[idx][target - arr[idx]] + 1;

			// not pick
			int notpick = dp[idx - 1][target];

			dp[idx][target]  = min(pick, notpick);
		}
	}

	int ans = dp[n - 1][x];
	if (ans >= 1e9) return -1;
	return ans;
}



int coinChange(vector<int>arr, int x) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(x + 1, -1));
	return  tabulationWay(arr, x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;

	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << coinChange(arr, k) << endl;

}