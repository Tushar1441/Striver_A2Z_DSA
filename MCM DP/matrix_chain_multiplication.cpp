#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int>arr) {
	if (i == j)return 0;

	int mini = 1e9;
	for (int k = i; k < j; k++) {
		int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k + 1, j, arr);
		mini = min(mini, steps);
	}

	return mini;
}

int solveMemoWay(int i, int j, vector<int>arr, vector<vector<int>>&dp) {
	if (i == j)return 0;
	if (dp[i][j] != -1)return dp[i][j];

	int mini = 1e9;
	for (int k = i; k < j; k++) {
		int steps = arr[i - 1] * arr[k] * arr[j] + solveMemoWay(i, k, arr, dp) + solveMemoWay(k + 1, j, arr, dp);
		mini = min(mini, steps);
	}

	return dp[i][j] =  mini;
}


int tabulationWay(vector<int>arr, int n) {

	int dp[n][n];

	// base case
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	// Explore all the states bottom-up
	for (int i = n - 1; i > 0; i--) {
		for (int j = i + 1; j < n; j++) {
			int mini = 1e9;
			for (int k = i; k < j; k++) {
				int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
				mini = min(mini, steps);
			}

			dp[i][j] =  mini;
		}
	}

	return dp[1][n - 1];

}


int matrixMultiplication(vector<int>&arr, int N) {
	vector<vector<int>>dp(N, vector<int>(N, -1));
	return solveMemoWay(1, N - 1, arr, dp);
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

	cout << matrixMultiplication(arr, n) << endl;

}