#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int w, vector<int>&profit, vector<int>&wt) {
	if (idx ==  0) {
		return profit[0] * (w / wt[0]);
	}

	//pick
	int pick = -1e9;
	if (wt[idx] <= w)pick = solve(idx, w - wt[idx], profit, wt) + profit[idx];

	//not pick'
	int notpick = solve(idx - 1, w, profit, wt);

	return max(pick, notpick);
}


int solveMemoWay(int idx, int w, vector<int>&profit, vector<int>&wt, vector<vector<int>>&dp) {
	if (idx ==  0) {
		return profit[0] * (w / wt[0]);
	}

	if (dp[idx][w] != -1)return dp[idx][w];

	//pick
	int pick = -1e9;
	if (wt[idx] <= w)pick = solveMemoWay(idx, w - wt[idx], profit, wt, dp) + profit[idx];

	//not pick'
	int notpick = solveMemoWay(idx - 1, w, profit, wt, dp);

	return dp[idx][w] = max(pick, notpick);
}





int tabulationWay(int n, int w, vector<int> &profit, vector<int> &weight) {
	vector<vector<int>>dp(n, vector<int>(w + 1, 0));

	// base case
	for (int i = 0; i <= w; i++) {
		dp[0][i] = profit[0] * (i / weight[0]) ;
	}

	for (int idx = 1; idx < n; idx++) {

		for (int wt = 0; wt <= w; wt++) {
			int pick = -1e9;
			if (weight[idx] <= wt)pick = dp[idx][wt - weight[idx]] + profit[idx];

			//not pick'
			int notpick = dp[idx - 1][wt];

			dp[idx][wt] = max(pick, notpick);
		}
	}

	return dp[n - 1][w];
}

int optimizedTabulationWay(int n, int w, vector<int> &profit, vector<int> &weight) {
	vector<int>prev(w + 1, 0), curr(w + 1, 0);

	// base case
	for (int i = 0; i <= w; i++) {
		prev[i] = profit[0] * (i / weight[0]) ;
	}

	for (int idx = 1; idx < n; idx++) {

		for (int wt = 0; wt <= w; wt++) {
			int pick = -1e9;
			if (weight[idx] <= wt)pick = curr[wt - weight[idx]] + profit[idx];

			//not pick'
			int notpick = prev[wt];

			curr[wt] = max(pick, notpick);
		}

		prev = curr;
	}

	return  prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	//Write your code here
	vector<vector<int>>dp(n, vector<int>(w + 1, -1));
	return tabulationWay(n , w, profit, weight);
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
	cout << unboundedKnapsack(n, k, arr1, arr2) << endl;

}