#include <bits/stdc++.h>
using namespace std;


int f1(int n, int m, vector<vector<int>>&arr) {
	// if col number goes out of bound.
	if (m < 0 || m >= arr[n].size())return -1e9;
	//if we reach the last row , then return the element.
	if (n == 0)return arr[n][m];


	// calculate all three possibilities.
	int fs = f1(n - 1, m - 1, arr, dp) + arr[n][m];
	int ss = f1(n - 1, m, arr, dp) + arr[n][m];
	int ts  = f1(n - 1, m + 1, arr, dp) + arr[n][m];

	//return max.
	return max(fs, max(ss, ts));


	// TC --> O(m * 3^(n))
	// there are exactly m starting indexes.
	// there are three choices at every index.and total depth will be n.
	// SC --> O(n) recursion stack space.
}


// memoization using DP array
int f2(int n, int m, vector<vector<int>>&arr, vector<vector<int>>&dp) {
	if (m < 0 || m >= arr[n].size())return -1e9;
	if (n == 0)return arr[n][m];
	if (dp[n][m] != -1)return dp[n][m];

	int fs = f1(n - 1, m - 1, arr, dp) + arr[n][m];
	int ss = f1(n - 1, m, arr, dp) + arr[n][m];
	int ts  = f1(n - 1, m + 1, arr, dp) + arr[n][m];

	return dp[n][m] = max(fs, max(ss, ts));

	// TC --> O(m * (n*m))
	// Here we are traversing all the elements exactly once with m starting indexes.
	// SC --> O(n) + O(n*m) recursion stack space + dp array space.
}


// bottom up tabulation approach
int f3(vector<vector<int>>&arr) {

	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>>dp(n, vector<int>(m, -1));
	//base case. storing the first row.
	for (int i = 0; i < m; i++) {
		dp[0][i] = arr[0][i];
	}


	// writing for loop for all posible states.
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int fs = INT_MIN, ts = INT_MIN;
			if (j > 0) fs = dp[i - 1][j - 1]  + arr[i][j];
			int ss = dp[i - 1][j]      + arr[i][j];
			if (j < m - 1) ts = dp[i - 1][j + 1]  + arr[i][j];

			dp[i][j] = max(fs, max(ss, ts));
		}
	}

	// the answer will be the maximum value in the last row.
	int maxi = dp[n - 1][0];

	for (int i = 1; i < m; i++) {
		maxi = max(maxi, dp[n - 1][i]);
	}

	return maxi;

	// TC --> O(n*m) + O(m) + O(m)
	// SC --> O(n*m)
}

// space optimisation
//using 1D array instead of 2D dp array
int f4(vector<vector<int>>&arr) {
	int n = arr.size();
	int m = arr[0].size();

	// initialise a 1D array and store the 1st row.
	vector<int>prev(m, 0);
	for (int i = 0; i < m; i++) {
		prev[i] = arr[0][i];
	}

	for (int i = 1; i < n; i++) {
		//create a temp array to store all the current row elements.
		vector<int>temp(m, 0);

		for (int j = 0; j < m; j++) {
			int fs = INT_MIN, ts = INT_MIN;
			if (j > 0) fs = prev[j - 1]  + arr[i][j];
			int ss = prev[j] + arr[i][j];
			if (j < m - 1) ts = prev[j + 1]  + arr[i][j];

			temp[j] = max(fs, max(ss, ts));
		}

		prev = temp;
	}

	int maxi = dp[n - 1][0];

	for (int i = 1; i < m; i++) {
		maxi = max(maxi, dp[n - 1][i]);
	}

	return maxi;
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>>dp(n, vector<int>(m, -1));
	// selecting starting point for falling.
	int ans = INT_MIN;
	for (int i = 0; i < m; i++) {
		ans = max(ans, f1(n - 1, i, matrix, dp));
	}

	return ans;
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
	vector<vector<int>>arr;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		arr.push_back(row);
	}

	cout << getMaxPathSum(arr) << endl;

}