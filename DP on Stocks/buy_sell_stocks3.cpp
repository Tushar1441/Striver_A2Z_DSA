#include <bits/stdc++.h>
using namespace std;


// Failed Approach --> Stored the indexes of the bought stock prices in an array.
// memory limit exceeded


// Simple Recursive Approach
int solve(int idx, vector<int>arr, int buy, int sell) {
	if (idx == arr.size() || sell == 0)return 0;

	int profit = 0;

	// if there is nothing bought earlier
	if (buy) {
		// buy it or not buy it
		profit = max(-arr[idx] + solve(idx + 1, arr, 0, sell) , solve(idx + 1, arr, 1, sell));
	}

	// if, have bought something but not sold yet
	else {
		// sell it or not sell it
		profit = max(arr[idx] + solve(idx + 1, arr, 1, sell - 1), solve(idx + 1, arr, 0, sell));
	}


	return profit;

	// TC --> O(2^n)
	// SC --> O(n)
}


int solveMemoWay(int idx, vector<int>arr, int buy, int sell, vector<vector<vector<int>>>&dp) {
	if (idx == arr.size() || sell == 0) {
		return 0;
	}

	if (dp[idx][buy][sell] != -1)return dp[idx][buy][sell];

	int profit = 0;

	// if there is nothing to sell
	if (buy) {
		// buy it or not buy it
		profit = max(-arr[idx] + solveMemoWay(idx + 1, arr, 0, sell, dp) , solveMemoWay(idx + 1, arr, 1, sell, dp));
	}

	// if have bought something but not sold yet
	else {
		// sell it or not sell it
		profit = max(arr[idx] + solveMemoWay(idx + 1, arr, 1, sell - 1, dp), solveMemoWay(idx + 1, arr, 0, sell, dp));
	}

	return dp[idx][buy][sell] = profit;

	// TC --> O(n*2)
	// SC --> O(2*n) + O(n)
}


int tabulationWay(vector<int>&prices) {
	int n = prices.size();
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));


	for (int i = n - 1; i >= 0; i--) {
		for (int buy = 0; buy < 2; buy++) {
			for (int cap = 1; cap <= 2; cap++) {

				if (buy) {
					// buy it or not buy it
					dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap] , dp[i + 1][1][cap]);
				}

				// if have bought something but not sold yet
				else {
					// sell it or not sell it
					dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
				}
			}
		}
	}

	return dp[0][1][2];
}


int optimizedTabulationWay(vector<int>&prices) {
	int n = prices.size();
	vector < vector << int>>next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));


	for (int i = n - 1; i >= 0; i--) {
		for (int buy = 0; buy < 2; buy++) {
			for (int cap = 1; cap <= 2; cap++) {

				if (buy) {
					// buy it or not buy it
					curr[buy][cap] = max(-prices[i] + next[0][cap] , next[1][cap]);
				}

				// if have bought something but not sold yet
				else {
					// sell it or not sell it
					curr[buy][cap] = max(prices[i] + next[1][cap - 1], next[0][cap]);
				}
			}
			next = curr;
		}
	}

	return next[1][2];
}




int maxProfit(vector<int>&prices) {
	// int n = prices.size();
	// vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
	// return solveMemoWay(0, prices, 1, 2, dp);

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
