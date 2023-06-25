#include <bits/stdc++.h>
using namespace std;

long solve(int idx, int* arr, int target) {
	if (target == 0)return 1;
	if (idx == 0) {
		if (target % arr[idx] == 0) return 1;
		return 0;
	}

	//pick
	long pick = 0;
	if (target >= arr[idx]) pick = solve(idx, arr, target - arr[idx]);

	// not pick
	long notpick = solve(idx - 1, arr, target);

	return pick + notpick;

	//TC --> O(2^t) here t is the max target.
	// SC --> O(n)
}

long solveMemoWay(int idx, int* arr, int target , vector<vector<long>>&dp) {
	if (target == 0)return 1;

	if (idx == 0) {
		if (target % arr[idx] == 0) return 1;
		return 0;
	}

	if (dp[idx][target] != -1)return dp[idx][target];
	//pick
	long pick = 0;
	if (target >= arr[idx]) pick = solveMemoWay(idx, arr, target - arr[idx], dp);

	// not pick
	long notpick = solveMemoWay(idx - 1, arr, target, dp);

	return dp[idx][target] = pick + notpick;

	//TC --> O(n*t) here t is the max target.
	// SC --> O(n) + O(n*t)
}

long tabulationWay(int *arr, int n, int value) {
	// int n = arr.size();
	vector<vector<long>>dp(n, vector<long>(value + 1, 0));

	for (int i = 0; i <= value; i++) {
		if (i % arr[0] ==  0)dp[0][i] = 1;
	}

	for (int idx = 1; idx < n; idx++) {
		for (int target = 0; target <= value; target++) {
			long pick = 0;
			if (target >= arr[idx]) pick = dp[idx][target - arr[idx]];

			// not pick
			long notpick = dp[idx - 1][target];

			dp[idx][target] = pick + notpick;
		}
	}

	return dp[n - 1][value];

	//TC --> O(n*t) here t is the max target.
	// SC --> O(n*t)

}

long optimizedTabulationWay(int *arr, int n, int value) {
	// int n = arr.size();
	vector<long>prev(value + 1, 0), curr(value + 1, 0);

	for (int i = 0; i <= value; i++) {
		if (i % arr[0] ==  0)prev[i] = 1;
	}

	for (int idx = 1; idx < n; idx++) {
		for (int target = 0; target <= value; target++) {
			long pick = 0;
			if (target >= arr[idx]) pick = curr[target - arr[idx]];

			// not pick
			long notpick = prev[target];

			curr[target] = pick + notpick;
		}

		prev = curr;
	}

	return prev[value];

	//TC --> O(n*t) here t is the max target.
	// SC --> O(t)
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
	//Write your code here
	// vector<vector<long>>dp(n, vector<long>(value + 1, -1));
	return optimizedTabulationWay(denominations, n,  value);
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

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;;
	}

	cout << countWaysToMakeChange(arr, n, k) << endl;

}