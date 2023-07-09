#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach -> Using two for loops, try all the possible subarrays with
// the given window size.
vector<int> maxSlidingWindow(vector<int>&arr, int k) {
    int n = arr.size();
    vector<int>ans;

    for (int i = 0; i <= n - k; i++) {
        int maxi = INT_MIN;
        for (int j = i; j < i + k; j++) {
            maxi = max(maxi, arr[j]);
        }
        ans.push_back(maxi);

    }

    return ans;

    // TC --> O(n*k) == O(n^2)
}



// Optimal Solution --> Using deque data structure
// Step1) store the window elements in decreasing order in the queue
// Step2) PopFront the out of bound elements from the queue i.e. the characers
// that are no longer included in the subarray window.
vector<int> maxSlidingWindow1(vector<int>&arr , int k) {
    vector<int>ans;
    deque<int>dq;

    for (int i = 0; i < arr.size(); i++) {
        if (!dq.empty() && dq.front() == i - k)dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        if (i >= k - 1)ans.push_back(arr[dq.front()]);
    }

    return ans;
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

    vector<int>ans = maxSlidingWindow1(arr, k);
    for (auto it : ans) {
        cout << it << " ";
    } cout << endl;

}