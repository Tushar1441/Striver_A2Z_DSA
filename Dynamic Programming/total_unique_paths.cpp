#include <bits/stdc++.h>
using namespace std;

// simple recursive approach
int count1(int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1)return 1;
    if (i == m || j == n)return 0;

    int r = count1(i, j + 1, m, n);
    int d = count1(i + 1, j, m, n);

    return (r + d);
    // TC --> O(2^(n*m))
    // SC --> O(n+m) --> recursion stack space
}


// using memoization
int count2( int i, int j, vector<vector<int>>&dp) {
    if (i == 0 && j == 0)return 1;
    if (i < 0 || j < 0)return 0;

    if (dp[i][j] != -1)return dp[i][j];

    int up = count2(i - 1, j, dp);
    int left = count2(i, j - 1, dp);

    return dp[i][j] = (up + left);

    // TC --> O(n*m)
    // SC --> O(n+m) + O(n*m)
}


// tabulation approach
int count(int m, int n, vector<vector<int>>&dp) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int up, left;
            if (i == 0 && j == 0)dp[i][j] = 1;
            else {
                if (i > 0)up = dp[i - 1][j];
                if (j > 0)left = dp[i][j - 1];
                dp[i][j] = up + left;
            }

        }
    }

    return dp[m - 1][n - 1];
}


// space optimisation
int count(int m, int n) {

    vector<int>prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int>temp(n, 0);
        for (int j = 0 ; j < n; j++) {
            if (i == 0 && j == 0)temp[j] = 1;
            else {
                int up = 0, left = 0;
                if ( i > 0 )up = prev[j];
                if (j > 0)left = temp[j - 1];
                temp[j] = up + left;
            }
        }

        prev = temp;
    }

    return prev[n - 1];
}


int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n, -1));
    int ans = count(m, n, dp);
    return ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, m;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;

}