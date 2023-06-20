#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, int r, int c, vector<vector<int>>&arr) {
	// out of bound cases for column index.
	if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c )return 0;

	// base case -- destination.
	// if both reaches the same column then return only one
	// else return sum of both.
	if (i == r - 1) {
		if (j1 == j2)return arr[i][j1];
		else return arr[i][j1] + arr[i][j2];
	}


	// trying out all the possible states.
	//there are three possible states for both Alice and Bob to move.

	// variable to find the maximum of all states.
	int maxi = -1e8;
	for (int k = -1; k <= 1; k++) {
		for (int l = -1; l <= 1; l++) {
			if (j1 == j2) maxi = max(maxi, arr[i][j1] + f(i + 1, j1 + k, j2 + l, r, c, arr));
			else maxi = max(maxi, arr[i][j1] + arr[i][j2] + f(i + 1, j1 + k, j2 + l, r, c, arr));
		}
	}
	return maxi;

	// TC --> O(3^n * 3^n) 3-3 choices for both alice and bob to move
	// SC --> O(n) recursion stack space.
}


// using memoization
// there are three 3 indexes to memoize, so we will take a 3D MATRIX;
int f1(int i, int j1, int j2, int r, int c, vector<vector<int>>&arr, vector<vector<vector<int>>>&dp) {
	if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c )return 0;


	if (i == r - 1) {
		if (j1 == j2)return arr[i][j1];
		else return arr[i][j1] + arr[i][j2];
	}

	if (dp[i][j1][j2] != -1)return dp[i][j1][j2];

	int maxi = -1e8;
	for (int k = -1; k <= 1; k++) {
		for (int l = -1; l <= 1; l++) {
			if (j1 == j2) maxi = max(maxi, arr[i][j1] + f1(i + 1, j1 + k, j2 + l, r, c, arr));
			else maxi = max(maxi, arr[i][j1] + arr[i][j2] + f1(i + 1, j1 + k, j2 + l, r, c, arr));
		}
	}
	return dp[i][j1][j2] = maxi;


	// TC --> O( 3*3 * n*m*m ) => O(n*m*m)
	// SC --> O(n) + O(n*m*m) recursion stack space + 3D vector
}


//tabulation approach -- bottom up
int f2(int n, int m, vector<vector<int>>&arr) {

	vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

	// base case
	// storing all the last row values into dp vector
	for (int j1 = 0; j1 < m; j1++) {
		for (int j2 = 0; j2 < m; j2++) {
			if (j1 == j2)dp[n - 1][j1][j2] = arr[n - 1][j1];
			else dp[n - 1][j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];
		}
	}


	//traversing all the posible states.
	for (int i = n - 2; i >= 0; i--) {
		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = 0; j2 < m; j2++) {

				// copy the recurrence relation
				int maxi = -1e8;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {

						// checking out of bound case
						if (j1 + k >= 0 && j1 + k < m && j2 + l >= 0 && j2 + l < m) {
							if (j1 == j2) maxi = max(maxi, arr[i][j1] + dp[i + 1][j1 + k][j2 + l]);
							else maxi = max(maxi, arr[i][j1] + arr[i][j2] + dp[i + 1][j1 + k][j2 + l]);
						}
					}
				}

				// store the result
				dp[i][j1][j2] = maxi;
			}
		}
	}


	return dp[0][0][m - 1];

	// TC --> O( 3*3 * n*m*m ) => O(n*m*m)
	// SC --> O(n*m*m) 3D vector
}



// we can also space optimize the code by taking just a 2D vector
// insted of a 3D vector because we olny need the next row.
int f3(int n, int m, vector<vector<int>>&arr) {

	vector<vector<int>>next(m, vector<int>(m, -1));

	// base case
	// storing all the last row values into dp vector
	for (int j1 = 0; j1 < m; j1++) {
		for (int j2 = 0; j2 < m; j2++) {
			if (j1 == j2)dp[n - 1][j1][j2] = arr[n - 1][j1];
			else dp[n - 1][j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];
		}
	}


	//traversing all the posible states.
	for (int i = n - 2; i >= 0; i--) {
		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = 0; j2 < m; j2++) {

				// copy the recurrence relation
				int maxi = -1e8;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {

						// checking out of bound case
						if (j1 + k >= 0 && j1 + k < m && j2 + l >= 0 && j2 + l < m) {
							if (j1 == j2) maxi = max(maxi, arr[i][j1] + dp[i + 1][j1 + k][j2 + l]);
							else maxi = max(maxi, arr[i][j1] + arr[i][j2] + dp[i + 1][j1 + k][j2 + l]);
						}
					}
				}

				// store the result
				dp[i][j1][j2] = maxi;
			}
		}
	}


	return dp[0][0][m - 1];

	// TC --> O( 3*3 * n*m*m ) => O(n*m*m)
	// SC --> O(n*m*m) 3D vector
}





int maximumChocolates(int r, int c, vector<vector<int>>&grid) {
	// give both the starting points as parameters
	// i will be same for both i.e 0
	// and j will be 0 for first and c-1 for second.

	// initialising a 3D DP vector
	// dp[r][c][c]
	vector<vector<vector<int>>>&dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

	int ans = f(0, 0, c - 1, r, c, grid, dp);
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

	cout << maximumChocolates(n, m, arr) << endl;

}