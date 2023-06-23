#include <bits/stdc++.h>
using namespace std;


// recursive solution using pick or not pick technique
int solve1(int idx, vector<int>&arr, int target) {
	if (target == 0)return 1;
	if (idx == 0)return (arr[0] == target);


	// pick
	int pick = 0;
	if (target >= arr[idx])pick = solve1(idx - 1, arr, target - arr[idx]);

	//not pick
	int notpick = solve1(idx - 1, arr, target);

	return pick + notpick;

	// TC --> O(2^n)
	// SC --> O(n)  --> recursion stack space
}


//memoize
int solve2(int idx, vector<int>&arr, int target, vector<vector<int>>&dp) {
	// slightly changing the base case because the array can contain leading 0's.

	if (idx == 0) {
		if (target == 0 && arr[0] == 0)
			return 2;
		if (target == 0 || target == arr[0])
			return 1;
		return 0;
	}

	if (dp[idx][target] != -1)return dp[idx][target];

	// pick
	int pick = 0;
	if (target >= arr[idx])pick = solve2(idx - 1, arr, target - arr[idx], dp);

	//not pick
	int notpick = solve2(idx - 1, arr, target, dp);

	return  dp[idx][target] = (pick + notpick);

	// TC : O(N*K)
	// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

	// SC --> O(N*K) + O(N)
}



// tabulation --> bottom up approach
int solve(vector<int>&arr, int k) {
	int n = arr.size();

	vector<vector<int>>dp(n, vector<int>(k + 1, -1));

	//base case
	if (arr[0] == 0)dp[0][0] = 2;
	else dp[0][0] = 1;

	//base case 2
	if (arr[0] != 0 &&  arr[0] <= k) dp[0][arr[0]] = 1;


	//explore states
	for (int idx = 1; idx < n; idx++) {
		for (int target = 1; target <= k; target++) {

			int pick = 0;
			if (target >= arr[idx]) {
				pick = dp[idx - 1][target - arr[idx]];
			}

			//not pick
			int notpick = dp[idx - 1][target];

			dp[idx][target] = (pick + notpick);
		}
	}

	return dp[n - 1][k];

}


int countSubsets(vector<int>&arr, int k) {
	vector<vector<int>>dp(arr.size(), vector<int>(k + 1, -1));
	return solve(arr, k);
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

	cout << countSubsets(arr, k) << endl;

}