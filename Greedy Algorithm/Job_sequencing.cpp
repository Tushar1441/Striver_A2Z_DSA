#include <bits/stdc++.h>
using namespace std;

int solve(int idx, vector<vector<int>>& jobs, int timer, int profit) {
    if (idx == jobs.size())return profit;

    // not pick the job
    int skip = solve(idx + 1, jobs, timer, profit);

    // pick the job only if deadline is less than the timer;
    int pick = INT_MIN;
    if (timer < jobs[idx][0]) {
        pick = solve(idx + 1, jobs, timer + 1, profit + jobs[idx][1]);
    }

    return max(pick, skip);
}


int maxProfit1(vector<vector<int>>& jobs) {
    sort(jobs.begin(), jobs.end());
    int n = jobs.size();
    return solve(0, jobs, 0, 0);

    // TC --> O(2^n + n*logn)
}

// ---------------------------------------------------------------

bool comp(vector<int>&a, vector<int>&b) {
    return (a.back() > b.back());
}

// Optimal Approach --> Greedy Algorithm
// Sort the jobs acc to decreasing order of their profit.
// Perform the task on the max possible deadline.
int maxProfit(vector<vector<int>>&jobs) {
    // sort the jobs
    sort(jobs.begin(), jobs.end(), comp);
    int n = jobs.size();

    // intialise a temp array to keep track of on which day a job is performed.
    // the length will be the max deadline because we assinging jobs on the given deadline
    int maxDeadline = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }
    vector<int>job(maxDeadline + 1, -1);

    // ans variable
    int profit = 0;

    // iterate on every task.
    for (int i = 0; i < n; i++) {
        // check for its max deadline availability in the temp array.
        for (int j = jobs[i][0]; j > 0; j--) {
            // if the day is not already marked then mark the day and
            // increase the profit.
            if (job[j] == -1) {
                job[j] = i;
                profit += jobs[i][1];
                break;
            }
        }
    }

    //return profit
    return profit;

    // TC --> O(n*logn + n*m) where m is the max deadline from all the jobs.
    // n*logn for sorting the array and then we are running a loop for n times
    // ic which each iteration can go on for m times in worst case.

    // SC --> O(m) temp array of size m.
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
        for (int j = 0; j < 2; j++) {
            cin >> temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }

    cout <<  maxProfit(arr) << endl;

}