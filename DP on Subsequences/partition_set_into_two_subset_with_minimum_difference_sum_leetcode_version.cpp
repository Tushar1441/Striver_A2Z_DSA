#include <bits/stdc++.h>
using namespace std;

// This is a slight variation from the previous question.
// The question statement states that both the partitions must contain equal number of elements.


// recursive Solution --> we will try out all the possible sum with n/2 elements.
// and return a dp vector.


int solve(int idx, vector<int>arr, int totalSum, int count , int sum) {
    if (count == arr.size() / 2 ) return sum;
    if (idx < 0)return 1e7;

    int s1 = solve(idx - 1, arr, totalSum, count++, sum + arr[idx]);

    int s2 = solve(idx - 1, arr, totalSum, count, sum);

    int ans = min( abs(totalSum - 2 * s1), abs(totalSum  - 2 * s2));
    cout << ans << " " << s1 << " " << s2 << " " << count << endl;
    return ans;
}



int  minSubsetSumDifference(vector<int>&arr) {
    int n = arr.size();
    int totalSum = 0;
    for (auto it : arr)totalSum += it;
    return solve(n - 1, arr, totalSum, 0, 0);
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

    cout << minSubsetSumDifference(arr) << endl;
}