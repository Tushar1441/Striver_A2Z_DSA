#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// simple recursive approach
int solve(int i, int j, vector<vector<int>>&arr, int sum) {
    if (i == 0 && j == 0)return sum;
    if (i < 0 || j < 0 )return 0;

    int up = INT_MAX, left = INT_MAX;
    if (i > 0)up = solve(i - 1, j, arr, sum + arr[i - 1][j]);
    if (j > 0)left = solve(i, j - 1, arr, sum + arr[i][j - 1]);

    return min(up , left);
    // TC --> O(2^(n*m))
    // SC --> O(n+m) --> recursion stack space
}


// using memoization
int solve1( int i, int j, vector<vector<int>>&arr, vector<vector<int>>&dp) {
    if (i == 0 && j == 0)return arr[i][j];
    if (i < 0 || j < 0)return 1e9;

    if (dp[i][j] != -1)return dp[i][j];

    int up = f(i - 1, j, arr, dp) + arr[i][j];
    int left = f(i, j - 1, arr, dp) + arr[i][j];

    return dp[i][j] = min(up , left);

    // TC --> O(n*m)
    // SC --> O(n+m) + O(n*m)
}


// tabulation approach
int solve2(int n, int m, vector<vector<int>>&arr, vector<vector<int>>&dp) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i == 0 && j == 0)dp[i][j] = grid[0][0];
            else {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)up = dp[i - 1][j] + grid[i][j];
                if (j > 0)left = dp[i][j - 1] + grid[i][j];
                dp[i][j] = min(up , left) ;
            }

        }
    }
    return dp[n - 1][m - 1];
}


// // space optimisation
int solve3(int n, int m, vector<vector<int>>&arr) {

    vector<int>prev(m, 0);

    for (int i = 0; i < m; i++) {
        vector<int>temp(m, 0);
        for (int j = 0 ; j < n; j++) {
            if (i == 0 && j == 0)temp[j] = arr[0][0];
            else {
                int up = INT_MAX, left = INT_MAX;
                if ( i > 0 )up = prev[j] + arr[i][j];
                if (j > 0)left = temp[j - 1] + arr[i][j];
                temp[j] = min(up, left);
            }
        }

        prev = temp;
    }

    return prev[n - 1];
}


int minPathSum(vector<vector<int>>&grid) {
    int n = grid.size();
    int m = grid[0].size();
    int sum = grid[n - 1][m - 1];
    vector<vector<int>>dp(n, vector<int>(m, -1));
    int ans = solve(n - 1, m - 1 , grid, sum);
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
    cin >> m >> n;
    vector<vector<int>>arr;
    for (int i = 0; i < m; i++) {
        vector<int>row;
        for (int j = 0; j < n; j++) {
            cin >> temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }

    cout << uniquePaths(m, n, arr) << endl;

}