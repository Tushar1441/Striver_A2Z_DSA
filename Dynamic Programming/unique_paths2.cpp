#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// simple recursive approach
int count1(int i, int j, vector<vector<int>>&arr) {
    if (i == 0 && j == 0)return 1;
    if (i < 0 || j < 0 || arr[i][j] == -1)return 0;

    int up = count1(i - 1, j, arr);
    int left = count1(i, j - 1, arr);

    return (up + left);
    // TC --> O(2^(n*m))
    // SC --> O(n+m) --> recursion stack space
}


// using memoization
int count2( int i, int j, vector<vector<int>>&arr, vector<vector<int>>&dp) {
    if (i == 0 && j == 0)return 1;
    if (i < 0 || j < 0 || arr[i][j] == -1)return 0;

    if (dp[i][j] != 0)return dp[i][j];

    int up = count2(i - 1, j, arr, dp) % mod;
    int left = count2(i, j - 1, arr, dp) % mod;

    return dp[i][j] = (up + left) % mod;

    // TC --> O(n*m)
    // SC --> O(n+m) + O(n*m)
}


// tabulation approach
int count3(int m, int n, vector<vector<int>>&arr, vector<vector<int>>&dp) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (arr[i][j] == -1)dp[i][j] = 0;
            else if (i == 0 && j == 0)dp[i][j] = 1;
            else {
                int up = 0, left = 0;
                if (i > 0)up = dp[i - 1][j] % mod;
                if (j > 0)left = dp[i][j - 1] % mod;
                dp[i][j] = (up + left) % mod;
            }

        }
    }

    return dp[m - 1][n - 1];
}


// space optimisation
int count(int m, int n, vector<vector<int>>&arr) {

    vector<int>prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int>temp(n, 0);
        for (int j = 0 ; j < n; j++) {
            if (arr[i][j] == -1)temp[j] = 0;
            else if (i == 0 && j == 0)temp[j] = 1;
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


int uniquePaths(int n, int m, vector<vector<int>>&mat) {
    vector<vector<int>>dp(n, vector<int>(m, -1));
    int ans = count3(n, m , mat, dp);
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