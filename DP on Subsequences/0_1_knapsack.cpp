#include <bits/stdc++.h>
using namespace std;

int solve1(int idx, vector<int> weight, vector<int> value, int maxValue, int maxWeight) {
	if (maxWeight == 0 || idx == -1)return maxValue;

	//pick
	int pick = INT_MIN;
	if (maxWeight >= weight[idx]) {
		pick = solve1(idx - 1, weight, value, maxValue + value[idx], maxWeight - weight[idx]);
	}

	// not pick
	int notpick = solve1(idx - 1, weight, value, maxValue, maxWeight);

	return max(pick, notpick);

	// TC --> O(2^n)
	// SC --> O(n)
}


//memoize
int solveMemoWay(int idx, vector<int> weight, vector<int> value, int maxWeight,
                 vector<vector<int>>&dp) {

	if (idx == 0) {
		if (weight[idx] <= maxWeight)return value[idx];
		return 0;
	}

	if (dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

	//pick
	int pick = INT_MIN;
	if (maxWeight >= weight[idx]) {
		pick =  value[idx] + solveMemoWay(idx - 1, weight, value, maxWeight - weight[idx], dp);
	}

	// not pick
	int notpick =  0 + solveMemoWay(idx - 1, weight, value, maxWeight, dp);

	return dp[idx][maxWeight] = max(pick, notpick);

	// TC --> O(N*K)
	// SC --> O(N) + O(N*K)
}


// tabulation
int tabulationWay(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>>dp(n, vector<int>(maxWeight + 1, 0));

	//base case
	for (int i = weight[0]; i <= maxWeight; i++) {
		dp[0][i] = value[0];
	}


	// visit all the possible states.
	for (int idx = 1; idx < n; idx++) {
		for (int wt = 0; wt <= maxWeight; wt++) {

			int pick = INT_MIN;
			if (weight[idx] <= wt) {
				pick =  value[idx] + dp[idx - 1][wt - weight[idx]];
			}

			// not pick
			int notpick =  0 + dp[idx - 1][wt];

			dp[idx][wt] = max(pick, notpick);
		}
	}

	return dp[n - 1][maxWeight];

	// TC --> O(N*k)
	// SC --> O(N*K)
}


int optimizedTabulationWay(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int>prev(maxWeight + 1, 0);

	//base case
	for (int i = weight[0]; i <= maxWeight; i++) {
		prev[i] = value[0];
	}

	// visit all the possible states.
	for (int idx = 1; idx < n; idx++) {
		for (int wt = 0; wt <= maxWeight; wt++) {

			int pick = INT_MIN;
			if (weight[idx] <= wt) {
				pick =  value[idx] + prev[wt - weight[idx]];
			}

			// not pick
			int notpick =  0 + prev[wt];
			prev[wt] = max(pick, notpick);
		}
	}


	return prev[maxWeight];
}


// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
// 	vector<vector<int>>dp(n, vector<int>(maxWeight + 1, -1));
// 	return solve1(n - 1, weight, value, maxWeight, dp);
// }


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;

	vector<int>arr1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	vector<int>arr2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}
	cout << optimizedTabulationWay(arr1, arr2, n, k) << endl;

}