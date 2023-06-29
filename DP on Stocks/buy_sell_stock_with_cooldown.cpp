#include <bits/stdc++.h>
using namespace std;

// Failed Approach --> Stored the indexes of the bought stock prices in an array.
// memory limit exceeded


int solve(int idx, vector<int>arr, int buy) {
	if (idx >= arr.size()) {
		return 0;
	}

	int profit = 0;

	// if there is nothing to sell
	if (buy) {
		// buy it or not buy it
		profit = max(-arr[idx] + solve(idx + 1, arr, 0) , solve(idx + 1, arr, 1));
	}

	// if have bought something but not sold yet
	else {
		// sell it or not sell it
		profit = max(arr[idx] + solve(idx + 2, arr, 1), solve(idx + 1, arr, 0));
	}

	return profit;

	// TC --> O(2^n)
	// SC --> O(n)
}


int solveMemoWay(int idx, vector<int>arr, int buy, vector<vector<int>>&dp) {
	if (idx >= arr.size()) {
		return 0;
	}

	if (dp[idx][buy] != -1)return dp[idx][buy];

	int profit = 0;

	// if there is nothing to sell
	if (buy) {
		// buy it or not buy it
		profit = max(-arr[idx] + solveMemoWay(idx + 1, arr, 0, dp) , solveMemoWay(idx + 1, arr, 1, dp));
	}

	// if have bought something but not sold yet
	else {
		// sell it or not sell it
		profit = max(arr[idx] + solveMemoWay(idx + 2, arr, 1, dp), solveMemoWay(idx + 1, arr, 0, dp));
	}

	return dp[idx][buy] = profit;

	// TC --> O(n*2)
	// SC --> O(2*n) + O(n)
}


int tabulationWay(vector<int>&prices) {
	int n = prices.size();
	vector<vector<int>>dp(n + 2, vector<int>(2, 0));

	for (int i = n - 1 ; i >= 0; i--) {
		for (int buy = 0; buy <= 1; buy++) {

			if (buy) {
				// buy it or not buy it
				dp[i][buy] = max(-prices[i] + dp[i + 1][0] , dp[i + 1][1]);
			}

			// if have bought something but not sold yet
			else {
				// sell it or not sell it
				dp[i][buy] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
			}

		}
	}

	return dp[0][1];
}


int optimizedTabulationWay(vector<int>&prices) {
	int n = prices.size();
	// vector<vector<int>>dp(n + 1, vector<int>(2, -1));
	vector<int>next(2, 0), curr(2, 0), next1(2, 0);


	for (int i = n - 1; i >= 0; i--) {
		for (int buy = 1; buy >= 0; buy--) {
			int profit = 0;

			if (buy) {
				// buy it or not buy it
				profit = max(-prices[i] + next[0] , next[1]);
			}

			// if have bought something but not sold yet
			else {
				// sell it or not sell it
				profit = max(prices[i] + next1[1], next[0]);
			}

			curr[buy] = profit;
		}
		next1 = next;
		next = curr;
	}

	return next[1];
}



int maxProfit(vector<int>&prices) {
	// int n = prices.size();
	// vector<vector<int>>dp(n + 2, vector<int>(2, -1));
	// return solveMemoWay(0, prices, 1, dp);

	return tabulationWay(prices);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	int temp;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << maxProfit(arr) << endl;
}
