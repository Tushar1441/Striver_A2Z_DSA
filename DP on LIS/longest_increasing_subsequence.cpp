#include <bits/stdc++.h>
using namespace std;


int solve(int idx, vector<int>arr, int last) {
	if (idx == arr.size()) {
		if (last == -1 || arr[idx] > arr[last])return 1;
		return 0;
	}

	// not pick
	int notPick = solve(idx + 1, arr, last);

	// pick
	int pick = INT_MIN;
	if (last == -1 || arr[last] < arr[idx]) pick = 1 + solve(idx + 1, arr, idx);

	return max(pick, notPick);

	// TC --> O(2^n)
	// SC --> O(n)
}


int solveMemoWay(int idx, vector<int>arr, int last, vector<vector<int>>&dp) {
	if (idx == arr.size()) return 0;

	if (dp[idx][last + 1] != -1)return dp[idx][last + 1];

	// not pick
	int notPick = solveMemoWay(idx + 1, arr, last, dp);

	// pick
	int pick = INT_MIN;
	if (last == -1 || arr[last] < arr[idx]) pick = 1 + solveMemoWay(idx + 1, arr, idx, dp);

	return dp[idx][last + 1] = max(pick, notPick);

	// TC --> O(2^n)
	// SC --> O(n)
}


int tabulationWay(vector<int>&nums) {
	int n = nums.size();
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int last = i - 1; last >= -1; last--) {

			int notPick = dp[i + 1][last + 1];

			int pick = INT_MIN;
			if (last == -1 || nums[last] < nums[i]) pick = 1 + dp[i + 1][i + 1];

			dp[i][last + 1] = max(pick, notPick);
		}
	}

	return dp[0][-1 + 1];
}

int optimizedTabulationWay(vector<int>&nums) {
	int n = nums.size();
	vector<int>next(n + 1, 0), curr(n + 1, 0);

	for (int i = n - 1; i >= 0; i--) {
		for (int last = i - 1; last >= -1; last--) {

			int notPick = next[last + 1];

			int pick = INT_MIN;
			if (last == -1 || nums[last] < nums[i]) pick = 1 + next[i + 1];

			curr[last + 1] = max(pick, notPick);
		}
		next = curr;
	}

	return next[0];
}

int lengthOfLIS(vector<int>&nums) {
	int n = nums.size();
	vector<vector<int>>dp(n, vector<int>(n + 1, -1));
	return solveMemoWay(0, nums, -1, dp);
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

	cout << lengthOfLIS(arr) << endl;
}