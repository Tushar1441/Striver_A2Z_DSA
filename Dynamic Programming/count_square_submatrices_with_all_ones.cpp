#include <bits/stdc++.h>
using namespace std;


int countSquare(vector<vector<int>> &arr, int n, int m) {
	vector<vector<int>> dp(n, vector<int>(m, 0));
	int sum = 0;

	for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
	for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] == 0) dp[i][j] = 0;
			else {
				dp[i][j] = 1 + min(dp[i - 1][j],
				                   min(dp[i - 1][j - 1], dp[i][j - 1]));
			}

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += dp[i][j];
		}
	}
	return sum;
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
	vector<vector<int>>nums1;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		nums1.push_back(row);
	}

	cout <<  countSquare(nums1, n, m) << endl;
}
