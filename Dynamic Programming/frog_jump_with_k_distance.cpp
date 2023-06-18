#include <bits/stdc++.h>
using namespace std;


// brute force recursion approach
// To calculate the min energy for the possible jumps,just use a for loop.
// instead of doing one by one.
int frogJump1(int idx, vector<int>&arr, int k) {
    if (idx == 0)return 0;
    int ans = INT_MAX;

    for (int i = 1; i <= k; i++) {

        if (idx >= i ) {
            int  cnt = frogJump1(idx - i, arr, k) + abs(arr[idx] - arr[idx - i]);
            ans = min(ans, cnt);
        }

    }

    return ans;
}



// memoization approach
int frogJump(int idx, vector<int>&arr, int k, vector<int>&dp) {
    if (idx == 0)return 0;
    dp[0] = 0;
    int ans = INT_MAX;
    if (dp[idx] != -1)return dp[idx];

    for (int i = 1; i <= k; i++) {
        if (idx >= i) {
            int cnt = frogJump(idx - i, arr, k, dp) + abs(arr[idx] - arr[idx - i]);
            ans = min(ans, cnt);
        }
    }

    return dp[idx] = ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, k, temp;
    cin >> n >> k;
    vector<int>arr;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int>dp(n + 1, -1);
    cout << frogJump(n - 1, arr, k, dp) << endl;

}