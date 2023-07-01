#include <bits/stdc++.h>
using namespace std;

// Note: The intuition is to first find the last balloon, then the second last, and so on.
// This is the sequence we need to follow to solve this problem.

int solve(int i, int j, vector<int>arr) {
	if (i > j)return 0;

	int maxi = -1e9;
	for (int k = i; k <= j; k++) {
		int coins = arr[i - 1] * arr[k] * arr[j + 1]
		            + solve(i, k - 1, arr) + solve(k + 1, j, arr);

		maxi = max(maxi, coins);
	}

	return maxi;
}

int solveMemoWay(int i, int j, vector<int>arr, vector<vector<int>>&dp) {
	if (i > j)return 0;
	if (dp[i][j] != -1)return dp[i][j];

	int maxi = -1e9;
	for (int k = i; k <= j; k++) {
		int coins = arr[i - 1] * arr[k] * arr[j + 1]
		            + solveMemoWay(i, k - 1, arr, dp) + solveMemoWay(k + 1, j, arr, dp);
		maxi = max(maxi, coins);
	}

	return dp[i][j] = maxi;
}

int tabulationWay(vector<int>&nums) {
	int n = nums.size();
	nums.push_back(1);
	nums.insert(nums.begin(), 1);
	vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));

	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= n; j++) {
			if (i > j)continue;
			int maxi = -1e9;
			for (int k = i; k <= j; k++) {
				int coins = nums[i - 1] * nums[k] * nums[j + 1]
				            + dp[i][k - 1] + dp[k + 1][j];
				maxi = max(maxi, coins);
			}

			dp[i][j] = maxi;
		}
	}

	return dp[1][n];
}

int maxCoins(vector<int>&nums) {
	// int n = nums.size();
	// nums.push_back(1);
	// nums.insert(nums.begin(), 1);
	// vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	// return solveMemoWay(1, n, nums, dp);

	return tabulationWay(nums);
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

	cout << maxCoins(arr) << endl;

}