#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int>cuts) {
	// the array is sorted, so if any point i crosses j, return 0.
	if (i > j)return 0;

	int mini = 1e9;
	for (int k = i; k <= j; k++) {
		int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts) + solve(k + 1, j, cuts);
		mini = min(mini, cost);
	}

	return mini;
}

int solveMemoWay(int i, int j, vector<int>cuts, vector<vector<int>>&dp) {
	// the array is sorted, so if any point i crosses j, return 0.
	if (i > j)return 0;

	if (dp[i][j] != -1)return dp[i][j];

	int mini = 1e9;
	for (int k = i; k <= j; k++) {
		int cost = cuts[j + 1] - cuts[i - 1] + solveMemoWay(i, k - 1, cuts, dp) + solveMemoWay(k + 1, j, cuts, dp);
		mini = min(mini, cost);
	}

	return dp[i][j] = mini;
}

int tabulationWay(vector<int>&cuts, int n) {
	int c = cuts.size();

	cuts.push_back(n);
	cuts.insert(cuts.begin(), 0);
	sort(cuts.begin(), cuts.end());

	vector<vector<int>>dp(c + 2, vector<int>(c + 2, 0));

	for (int i = c; i > 0; i--) {
		for (int j = 1; j <= c; j++) {

			if (i > j)continue;
			int mini = 1e9;
			for (int k = i; k <= j; k++) {
				int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
				mini = min(mini, cost);
			}

			dp[i][j] = mini;
		}
	}

	return dp[1][c];
}


int minCuttingCost(vector<int>&cuts, int n) {

	// int c = cuts.size();
	// // insert 0 and n at the start and the ending
	// cuts.push_back(n);
	// cuts.insert(cuts.begin(), 0);
	// sort(cuts.begin(), cuts.end());

	// vector<vector<int>>dp(c + 1, vector<int>(c + 1, -1));
	// i = first cut next to 0
	// j = last cut prior to n
	// return solveMemoWay(1, c, cuts, dp);
	return tabulationWay(cuts, n);

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n >> m;
	vector<int>cuts;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		cuts.push_back(temp);
	}
	cout << minCuttingCost(cuts, n) << endl;

}