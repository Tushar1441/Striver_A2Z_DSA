#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution --> using simple recursion
int frogJump1(int n, vector<int> &heights)
{
    if (n == 0)return 0;

    int left = frogJump1(n - 1, heights) + abs(heights[n] - heights[n - 1]);

    int right = INT_MAX;
    if (n > 1) right = frogJump1(n - 2, heights) + abs(heights[n] - heights[n - 2]);

    return min(left, right);
}


// Optimal Solution --> Using Memoization
int frogJump2(int idx, vector<int>&heights, vector<int>&dp)
{
    if (idx == 0)return 0;
    if (dp[idx] != -1)return dp[idx];


    int left = frogJump2(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

    int right = INT_MAX;
    if (idx > 1) right = frogJump2(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

    return dp[idx] =  min(left, right);

    // TC --> O(n)
    // SC --> O(n) + O(n)
}


// tabulation approach
int frogJump3(int n, vector<int>&heights, vector<int>&dp) {
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(fs, ss);
    }

    return dp[n - 1];

    // TC --> O(n)
    // SC --> O(n)
}

// Performing space optimisation
int frogJump4(int n, vector<int>&heights) {
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)ss = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(fs, ss);

        prev2 = prev;
        prev = curr;
    }

    return prev;
    // TC --> O(n)
    // SC --> O(1)
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
    vector<int>dp(n + 1, -1);
    cout << frogJump(n - 1, arr, dp) << endl;

}