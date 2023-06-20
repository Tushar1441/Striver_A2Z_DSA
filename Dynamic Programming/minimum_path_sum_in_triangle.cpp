#include <bits/stdc++.h>
using namespace std;

// Simple Recursive Approach
int f1(int row, int col, vector<vector<int>>&arr) {
	if (row == arr.size() - 1) {
		return arr[row][col];
	}

	int down = f1(row + 1, col, arr) + arr[row][col];
	int leftDown = f1(row + 1, col + 1, arr) + arr[row][col];

	return min(down, leftDown);

	// TC --> O(2^(1+2+3+.....n)) --> O( 2 ^ (n*(n+1)/2) )
	// SC --> O(N)

}

// Performing memoization
int f2(int row, int col, vector<vector<int>>&arr, vector<vector<int>>&dp) {
	if (row == arr.size() - 1) {
		return arr[row][col];
	}
	if (dp[row][col] != -1)return dp[row][col];

	int down = f2(row + 1, col, arr, dp) + arr[row][col];
	int leftDown = f2(row + 1, col + 1, arr, dp) + arr[row][col];

	return dp[row][col] = min(down, leftDown);

	// TC --> O(1+2+3+.....n) --> O(n*(n+1)/2)
	// SC --> O(n) + O(n*n)
}


// performing tabulation bottom up approach
// this time we are top down recursion from index 0 to n
// so , the bottom up approach will be from n-1 to 0.
int f3(int n, vector<vector<int>>&arr, vector<vector<int>>&dp) {

	// base case
	// store all the last row values.
	for (int i = 0; i < n; i++) {
		dp[n - 1][i] = arr[n - 1][i];
	}


	for (int row = n - 2; row >= 0; row--) {
		for (int col = row; col >= 0; col--) {
			int down = dp[row + 1][col] + arr[row][col];
			int leftdown = dp[row + 1][col + 1] + arr[row][col];

			dp[row][col] = min(down, leftdown);
		}
	}

	// Before, we were returning last dp element
	// This time we will return first element.
	return dp[0][0];

	// TC --> O(n*(n+1)/2)
	// SC --> O(n*n)
}

// performing space optimisation
int f(int n, vector<vector<int>>&arr) {

	// base case
	// store all the last row values.
	vector<int> prev(n);
	for (int i = 0; i < n; i++) {
		prev[i] = arr[n - 1][i];
	}


	for (int row = n - 2; row >= 0; row--) {
		vector<int>temp(n, 0);
		for (int col = row; col >= 0; col--) {
			int down = prev[col] + arr[row][col];
			int leftdown = prev[col + 1] + arr[row][col];

			temp[col] = min(down, leftdown);
		}

		prev = temp;
	}

	// Before, we were returning last dp element
	// This time we will return first element.
	return prev[0];

}

int minimumPathSum(vector<vector<int>>& triangle) {
	// Write your code here.
	int n = triangle.size();
	vector<vector<int>>dp(n, vector<int>(n, -1));
	if (n == 1)return triangle[0][0];
	return  f(0, 0, triangle, dp);

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
	vector<vector<int>>arr;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j <= i; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		arr.push_back(row);
	}

	cout << minimumPathSum(arr) << endl;

}