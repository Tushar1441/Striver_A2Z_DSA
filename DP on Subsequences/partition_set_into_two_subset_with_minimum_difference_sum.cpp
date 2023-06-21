#include <bits/stdc++.h>
using namespace std;


int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += arr[i];
    int target = totalSum;

    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if (arr[0] <= target) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int k = 1; k <= target; k++) {
            bool pick = false;
            if (k >= arr[i]) pick = prev[k - arr[i]];

            bool notpick = prev[k];
            curr[k] = pick || notpick;
            //
            prev = curr;
        }


        int mini = 1e9;
        for (int s1 = 0; s1 <= totalSum / 2; s1++)
        {
            if (prev[s1] == true) {
                int diff =  abs((totalSum - s1) - s1);
                mini = min(mini, diff);
            }
        }
    }

    return mini;

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

    cout << canPartition(arr, n) << endl;
}