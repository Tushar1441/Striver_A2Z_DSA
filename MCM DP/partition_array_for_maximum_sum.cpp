#include <bits/stdc++.h>
using namespace std;


int solve(int i, int n, int k, vector<int>arr) {
	if (i == n)return 0;

	int maxSum =  INT_MIN, max_element = INT_MIN, len = 0;

	for (int idx = i; idx < min(n, i + k); idx++) {
		// updating the max_element for every subarray/window
		max_element = max(arr[idx], max_element);

		// update the length of the window
		len++;

		// Add the current subarray sum and call the recursion function to take care of the
		// right half of the partition.
		int sum = max_element * (len) + solve(idx + 1, n, k, arr);
		maxSum = max(maxSum, sum);
	}

	return maxSum;
}


int solveMemoWay(int i, int n, int k, vector<int>arr, vector<int>&dp) {
	if (i == n)return 0;
	if (dp[i] != -1)return dp[i];

	int maxSum =  INT_MIN, max_element = INT_MIN, len = 0;

	for (int idx = i; idx < min(n, i + k); idx++) {
		// updating the max_element for every subarray/window
		max_element = max(arr[idx], max_element);
		len++;
		int sum = max_element * (len) + solveMemoWay(idx + 1, n, k, arr, dp);
		maxSum = max(maxSum, sum);
	}

	return dp[i] =  maxSum;
}

int tabulationWay(vector<int>&nums, int k) {
	int n = nums.size();
	vector<int>dp(n + 1, 0);

	for (int i = n - 1; i >= 0; i--) {
		int maxSum =  INT_MIN, max_element = INT_MIN, len = 0;

		for (int idx = i; idx < min(n, i + k); idx++) {
			// updating the max_element for every subarray/window
			max_element = max(nums[idx], max_element);
			len++;
			int sum = max_element * (len) + dp[idx + 1];
			maxSum = max(maxSum, sum);
		}

		dp[i] =  maxSum;
	}

	return dp[0];
}


int maxSumAfterPartitioning(vector<int>nums, int k) {
	// int n = nums.size();
	// vector<int>dp(n + 1, -1);
	// return solveMemoWay(0, n, k, nums, dp);

	return tabulationWay(nums, k);
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

	cout << maxSumAfterPartitioning(arr, k) << endl;
}