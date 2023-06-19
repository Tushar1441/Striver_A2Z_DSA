#include <bits/stdc++.h>
using namespace std;

// Simple recursive solution
int maximumNonAdjacantSum1(int idx, vector<int>&arr) {
    if (idx >= arr.size())return 0;

    //pick the element and move 2 indexes
    int left = maximumNonAdjacantSum1(idx + 2, arr) + arr[idx];
    int right = maximumNonAdjacantSum1(idx + 1, arr);

    return max(left, right);

    // TC --> O(2^n)
}


// Memoization
int maximumNonAdjacantSum2(int idx, vector<int>&arr, vector<int>&dp) {
    if (idx >= arr.size())return 0;
    if (dp[idx] != -1)return dp[idx];

    int left = maximumNonAdjacantSum2(idx + 2, arr, dp) + arr[idx];
    int right = maximumNonAdjacantSum2(idx + 1, arr, dp);

    return dp[idx] = max(left, right);

    // TC --> O(n)
    // SC --> O(n) + O(n)
}


//tabulation approach -- bottom up
int maximumNonAdjacantSum3(int n, vector<int>&arr, vector<int>&dp) {
    if (arr.size() == 1)return arr[0];

    dp[0] = arr[0];
    dp[1] = max(arr[0] , arr[1]);

    for (int i = 2; i < n; i++) {
        int fs = dp[i - 2] + arr[i];
        int ss = dp[i - 1];

        dp[i] = max(fs, ss);
    }

    return dp[n - 1];

    // TC --> O(n)
    // SC --> O(n)
}


// space optimisation
int maximumNonAdjacantSum(int n, vector<int>&arr) {
    if (arr.size() == 1)return arr[0];

    int prev2 = arr[0];
    int prev = max(arr[0] , arr[1]);

    for (int i = 2; i < n; i++) {
        int fs = prev2 + arr[i];
        int ss = prev;

        int curr = max(fs, ss);

        prev2 = prev;
        prev = curr;
    }

    return prev;

    // TC --> O(n)
    // SC --> O(n)
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
    vector<int>dp(n, -1);
    cout << maximumNonAdjacantSum(n, arr) << endl;

    // for (auto it : dp)cout << it << " ";
    // cout << endl;

}