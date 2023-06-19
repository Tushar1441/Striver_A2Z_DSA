#include <bits/stdc++.h>
using namespace std;

int solve1(int idx, vector<vector<int>>&arr, int last) {
    if (idx == 0) {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (last != i)maxi = max(maxi, arr[0][i]);
        }
        return maxi;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int point = arr[idx][i] + solve1(idx - 1, arr, i);
            maxi = max(maxi, point);
        }
    }

    return maxi;

    // TC --> O(3* 2^n-1) == O(2^n)
    // SC --> O(1)
}

// In the above solution, there are many overlapping subproblems.
// To perform memoization, we have to remember two things --> index and the last picked task.
// So, initialise a 2D vector dp to store all the values.
int solve2(int idx, vector<vector<int>>&arr, int last, vector<vector<int>>&dp) {
    if (idx == 0) {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (last != i)maxi = max(maxi, arr[0][i]);
        }
        return maxi;
    }

    if (dp[idx][last] != -1)return dp[idx][last];


    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int point = arr[idx][i] + solve(idx - 1, arr, i, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[idx][last] = maxi;

    // TC --> O(N*4)*3
    // SC --> O(N) + O(N*4);
}

// performing Tabulation Bottom Up Approach.
int solve3(int n, vector<vector<int>>&arr, vector<vector<int>>&dp) {


    //1st Step ->  Store all the base cases in the dp array
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));


    //2nd step --> Run a for loop for all the remaining indexes.
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last] , point);
                }
            }
        }
    }

    return dp[n - 1][3];

    // TC --> O(N*4*3)
    // SC --> O(N*4);
}

// performing Tabulation Bottom Up Approach.
int solve(int n, vector<vector<int>>&arr) {

    vector<int>prev(4, 0);
    //1st Step ->  Store all the base cases in the dp array
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));


    //2nd step --> Run a for loop for all the remaining indexes.
    for (int day = 1; day < n; day++) {
        vector<int>temp(4, 0);
        for (int last = 0; last < 4; last++) {
            temp[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    temp[last] = max(temp[last] , arr[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];

    // TC --> O(N*4*3)
    // SC --> O(4);
}

int ninjaTraining(int n, vector<vector<int>>&arr) {
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return solve(n - 1, arr, 3, dp);
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
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }

    cout << ninjaTraining(n, arr) << endl;

}