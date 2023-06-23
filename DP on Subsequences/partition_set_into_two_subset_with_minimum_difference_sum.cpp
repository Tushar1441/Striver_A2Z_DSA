#include <bits/stdc++.h>
using namespace std;

// To solve this question, first we need to see what did we store in the 2d dp
// vector in the previous question.
// We were storing a bool value yes or no for every target value ranging
// from 0 to k corresponding to an index value.

// In this question, we have to divide the subarray into two parts with min sum difference
// To do that we will just fill out the dp vector for all the sum values achieved
// in the range of 0 to totalsum.
// Then we will pick two sum values from the dp array such that s1 + s2 == totalsum
// and abs(s1-s2) is as minimum as possible.



// top down DP Approach
int minSubsetSumDifference(vector<int>& arr, int n)
{
    // calculate the totalSum of the array elements.
    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += arr[i];
    int target = totalSum;

    // initialise a 1D dp array which contains only the prev
    vector<bool> prev(target + 1, false) , curr(target + 1, false);

    // base case 1
    curr[0] = prev[0] = true; // if target == 0, ans will be true.

    // base case 2
    // if last element if equal to the remaining target,ans will be true.
    if (arr[0] <= target) prev[arr[0]] = true;  // put a boundary check also.


    // try out all the possible states.
    for (int i = 1; i < n; i++) {

        for (int k = 1; k <= target; k++) {

            bool pick = false;
            if (k >= arr[i]) pick = prev[k - arr[i]];

            bool notpick = prev[k];

            curr[k] = pick || notpick;
            prev = curr;
        }

    }

    // now the dp array is fully marked.

    // initialise the min diff with INT_MAX
    int mini = 1e9;
    // go through all the sum in the range of 0 to totalSum/2.
    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (prev[s1] == true) {
            // s1 + s2 = totalSum   ==>  s2 = totalsum - s1
            int diff =  abs((totalSum - s1) - s1);
            mini = min(mini, diff);
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